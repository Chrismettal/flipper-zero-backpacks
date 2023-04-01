//-----------------------------------------------------------------------------
//  ESP32 / SD backpack selftest
//-----------------------------------------------------------------------------
//
// Small program to test functionality of the ESP32 / SD backpack
// to be run without being plugged into a Flipper, but with a serial
// terminal being connected through the USB-C jack
//
// Stuff that could be tested (Not neccessarily all implemented yet):
// - Serial communication through the USB jack
// - Open up a Wifi AP
// - Fade through all LED colors
// - R/W to/from a plugged in SD card
// - Apply PullUps to LPUART lines and read if voltage is HIGH
// - Output /something/ to all remaining ESP GPIOs


//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
// General
#include <Arduino.h>
// SD Card
#include "FS.h"
#include "SD.h"
#include "SPI.h"
// Wifi
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

//-----------------------------------------------------------------------------
//  Constants
//-----------------------------------------------------------------------------
// GPIOs
#define PIN_FIRST_LED       4
#define PIN_LAST_LED        6
#define PIN_I2C_PULLUP      3
#define PIN_LPUART_RX       17
#define PIN_LPUART_TX       18
// Wifi
const char *SSID          = "SelftestAP";
const char *PASS          = "SelftestAP";
// General
#define MAX_PWM             255


//-----------------------------------------------------------------------------
//  Variables
//-----------------------------------------------------------------------------
bool singleResult;
bool overallResult;


//-----------------------------------------------------------------------------
//  Macros
//-----------------------------------------------------------------------------
#define SERIAL_DIVIDER Serial.println("----------------------------------------")


//-----------------------------------------------------------------------------
//  setup
//-----------------------------------------------------------------------------
void setup() {

  //---------------------------------------------------------------------------
  //  Serial
  //---------------------------------------------------------------------------
  Serial.begin(115200);
  SERIAL_DIVIDER;
  Serial.println("ESP32 backpack starting self test..");
  SERIAL_DIVIDER;

  //---------------------------------------------------------------------------
  //  GPIO setup
  //---------------------------------------------------------------------------
  // LEDs
  for (int led = PIN_FIRST_LED; led <= PIN_LAST_LED; led++) {
    pinMode(led, OUTPUT);
  }

  // I2C
  pinMode(PIN_I2C_PULLUP, OUTPUT);
  pinMode(PIN_LPUART_RX,  INPUT);
  pinMode(PIN_LPUART_TX,  INPUT);


  //---------------------------------------------------------------------------
  //  Tests
  //---------------------------------------------------------------------------
  // Overall result memory
  overallResult = HIGH;

  //-----------------------------------
  // I2C
  //-----------------------------------
  // Test for low pullups
  SERIAL_DIVIDER;
  Serial.println("Starting I2C pin selftests");
  Serial.println("Disabling pullups");
  digitalWrite(PIN_I2C_PULLUP, LOW);
  delay(50);

  singleResult = HIGH;

  if (!digitalRead(PIN_LPUART_RX)) {
    Serial.println("OK  - GPIO_17 (LPUART_RX) low");
  } else {
    Serial.println("BAD - GPIO_17 (LPUART_RX) stuck high");
    singleResult = LOW;
  }

  if (!digitalRead(PIN_LPUART_TX)) {
    Serial.println("OK  - GPIO_18 (LPUART_TX) low");
  } else {
    Serial.println("BAD - GPIO_18 (LPUART_TX) stuck high");
    singleResult = LOW;
  }

  // Test for high pullups
  Serial.println("Enabling pullups");
  digitalWrite(PIN_I2C_PULLUP, HIGH);
  delay(50);

  if (digitalRead(PIN_LPUART_RX)) {
    Serial.println("OK  - GPIO_17 (LPUART_RX) high");
  } else {
    Serial.println("BAD - GPIO_17 (LPUART_RX) stuck low");
    singleResult = LOW;
  }

  if (digitalRead(PIN_LPUART_TX)) {
    Serial.println("OK  - GPIO_18 (LPUART_TX) high");
  } else {
    Serial.println("BAD - GPIO_18 (LPUART_TX) stuck low");
    singleResult = LOW;
  }

  // Print individual result
  SERIAL_DIVIDER;
  if (singleResult) {
    Serial.println("OK  - I2C Pullup tests OK!");
  } else {
    Serial.println("BAD - I2C Pullup tests failed!");
  }

  // Combine test results
  overallResult = overallResult && singleResult;

  //-----------------------------------
  // SD card
  //-----------------------------------
  singleResult = HIGH;
  SERIAL_DIVIDER;
  Serial.println("Starting SD card test");

  // Try mounting card
  if(!SD.begin()){
    Serial.println("BAD - Card Mount Failed");
    singleResult = LOW;
  } else {
    uint8_t cardType = SD.cardType();

    // Find card type
    if(cardType == CARD_NONE){
        Serial.println("BAD - No SD card attached");
        singleResult = LOW;
    } else {

      Serial.print("SD Card Type: ");
      if(cardType == CARD_MMC){
          Serial.println("MMC");
      } else if(cardType == CARD_SD){
          Serial.println("SDSC");
      } else if(cardType == CARD_SDHC){
          Serial.println("SDHC");
      } else {
          Serial.println("UNKNOWN");
      }

      // Print SD size
      Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
      Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));

      // Print individual result
      SERIAL_DIVIDER;
      Serial.println("OK  - SD card found and mounted");
    }
  }

  // Combine test results
  overallResult = overallResult && singleResult;


  //-----------------------------------
  // Evaluation
  //-----------------------------------
  SERIAL_DIVIDER;
  if (overallResult) {
    Serial.println("OK  - All automated tests passed!");
  } else {
    Serial.println("BAD - One or more automated tests failed!");
  }

  SERIAL_DIVIDER;
  Serial.println("Starting manual tests");


  //-----------------------------------
  // Wifi
  //-----------------------------------
  SERIAL_DIVIDER;
  Serial.println("Creating Wifi access point");

  //Start AP
  if (!WiFi.softAP(SSID, PASS)) {
    Serial.println("BAD - Can't start Access point!");
  } else {
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("OK  - AP created, IP: ");
    Serial.println(myIP);
    Serial.println("Please try connecting to AP 'SelftestAP' manually using the password 'SelftestAP'");
  }


  //-----------------------------------
  // LED
  //-----------------------------------
  SERIAL_DIVIDER;
  Serial.println("Starting LED test, please observe if LED shows Red, Green and Blue");

}


//-----------------------------------------------------------------------------
//  loop
//-----------------------------------------------------------------------------
void loop() {

  // Step through all LEDs
  for (int led = PIN_FIRST_LED; led <= PIN_LAST_LED; led++) {

    // Dim up
    for (int value = 0; value <= MAX_PWM; value++) {
      analogWrite(led, value);
      delay(1);
    }

    // Dim down
    for (int value = MAX_PWM; value >= 0; value--) {
      analogWrite(led, value);
      delay(1);
    }

  }

}
