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
#include "USB.h"
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
#define PIN_LED_R           6
#define PIN_LED_G           5
#define PIN_LED_B           4
#define PIN_I2C_PULLUP      3
#define PIN_LPUART_RX       17
#define PIN_LPUART_TX       18
// List of all GPIOs, HIGH for every GPIO that is going to be tested
#define NUMBER_GPIOS        43
const bool gpios[NUMBER_GPIOS] = {
  0,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1
};

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
unsigned long gpioStartTime;
USBCDC USBSerial;


//-----------------------------------------------------------------------------
//  Macros
//-----------------------------------------------------------------------------
#define SERIAL_DIVIDER USBSerial.println("----------------------------------------")


//-----------------------------------------------------------------------------
//  setup
//-----------------------------------------------------------------------------
void setup() {

  //---------------------------------------------------------------------------
  //  Serial
  //---------------------------------------------------------------------------

  USBSerial.enableReboot(HIGH);  
  USBSerial.begin(115200);
  USB.begin();

  // wait for serial connection
  //while (!USBSerial){;}
  USBSerial.println("Hoi!");
  delay(1000);


  SERIAL_DIVIDER;
  USBSerial.println("ESP32 backpack starting self test..");
  SERIAL_DIVIDER;

  delay(1000);

  //---------------------------------------------------------------------------
  //  GPIO setup
  //---------------------------------------------------------------------------
  // LEDs
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  analogWrite(PIN_LED_R, MAX_PWM);
  analogWrite(PIN_LED_G, MAX_PWM);
  analogWrite(PIN_LED_B, MAX_PWM);


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
  USBSerial.println("Starting I2C pin selftests");
  USBSerial.println("Disabling pullups");
  digitalWrite(PIN_I2C_PULLUP, LOW);
  delay(50);

  singleResult = HIGH;

  if (!digitalRead(PIN_LPUART_RX)) {
    USBSerial.println("OK  - GPIO_17 (LPUART_RX) low");
  } else {
    USBSerial.println("BAD - GPIO_17 (LPUART_RX) stuck high");
    singleResult = LOW;
  }

  if (!digitalRead(PIN_LPUART_TX)) {
    USBSerial.println("OK  - GPIO_18 (LPUART_TX) low");
  } else {
    USBSerial.println("BAD - GPIO_18 (LPUART_TX) stuck high");
    singleResult = LOW;
  }

  // Test for high pullups
  USBSerial.println("Enabling pullups");
  digitalWrite(PIN_I2C_PULLUP, HIGH);
  delay(50);

  if (digitalRead(PIN_LPUART_RX)) {
    USBSerial.println("OK  - GPIO_17 (LPUART_RX) high");
  } else {
    USBSerial.println("BAD - GPIO_17 (LPUART_RX) stuck low");
    singleResult = LOW;
  }

  if (digitalRead(PIN_LPUART_TX)) {
    USBSerial.println("OK  - GPIO_18 (LPUART_TX) high");
  } else {
    USBSerial.println("BAD - GPIO_18 (LPUART_TX) stuck low");
    singleResult = LOW;
  }

  // Print individual result
  SERIAL_DIVIDER;
  if (singleResult) {
    USBSerial.println("OK  - I2C Pullup tests OK!");
  } else {
    USBSerial.println("BAD - I2C Pullup tests failed!");
  }

  // Combine test results
  overallResult = overallResult && singleResult;

  
  //-----------------------------------
  // SD card
  //-----------------------------------
  /*
  singleResult = HIGH;
  SERIAL_DIVIDER;
  USBSerial.println("Starting SD card test");


  SPIClass spi = SPIClass(HSPI);
  spi.begin(36, 37, 35, 10);


  // Try mounting card
  if(!SD.begin(10, spi)){
    USBSerial.println("BAD - Card Mount Failed");
    singleResult = LOW;
  } else {
    uint8_t cardType = SD.cardType();

    // Find card type
    if(cardType == CARD_NONE){
        USBSerial.println("BAD - No SD card attached");
        singleResult = LOW;
    } else {

      USBSerial.print("SD Card Type: ");
      if(cardType == CARD_MMC){
          USBSerial.println("MMC");
      } else if(cardType == CARD_SD){
          USBSerial.println("SDSC");
      } else if(cardType == CARD_SDHC){
          USBSerial.println("SDHC");
      } else {
          USBSerial.println("UNKNOWN");
      }

      // Print SD size
      USBSerial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
      USBSerial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));

      // Print individual result
      SERIAL_DIVIDER;
      USBSerial.println("OK  - SD card found and mounted");
    }
  }

  // Combine test results
  overallResult = overallResult && singleResult;
  */

  //-----------------------------------
  // Evaluation
  //-----------------------------------
  SERIAL_DIVIDER;
  SERIAL_DIVIDER;
  if (overallResult) {
    USBSerial.println("OK  - All automated tests passed!");
  } else {
    USBSerial.println("BAD - One or more automated tests failed!");
  }
  SERIAL_DIVIDER;
  SERIAL_DIVIDER;
  USBSerial.println("Starting manual tests");


  //-----------------------------------
  // Wifi
  //-----------------------------------
  SERIAL_DIVIDER;
  USBSerial.println("Creating Wifi access point");

  //Start AP
  if (!WiFi.softAP(SSID, PASS)) {
    USBSerial.println("BAD - Can't start Access point!");
  } else {
    IPAddress myIP = WiFi.softAPIP();
    USBSerial.print("OK  - AP created, IP: ");
    USBSerial.println(myIP);
    USBSerial.println("Please try connecting to AP 'SelftestAP' manually using the password 'SelftestAP'");
  }


  //-----------------------------------
  // LED
  //-----------------------------------
  SERIAL_DIVIDER;
  USBSerial.println("Starting LED test, please observe if LED shows R, G then B");

  // Blink all colors a few times
  for (int iteration = 1; iteration <= 3; iteration++) {
    // Red
    for (int value = MAX_PWM; value >= 0; value--) {
      analogWrite(PIN_LED_R, value);
      delay(1);
    }
    for (int value = 0; value <= MAX_PWM; value++) {
      analogWrite(PIN_LED_R, value);
      delay(1);
    }
    // Green
    for (int value = MAX_PWM; value >= 0; value--) {
      analogWrite(PIN_LED_G, value);
      delay(1);
    }
    for (int value = 0; value <= MAX_PWM; value++) {
      analogWrite(PIN_LED_G, value);
      delay(1);
    }
    // Blue
    for (int value = MAX_PWM; value >= 0; value--) {
      analogWrite(PIN_LED_B, value);
      delay(1);
    }
    for (int value = 0; value <= MAX_PWM; value++) {
      analogWrite(PIN_LED_B, value);
      delay(1);
    }

    delay(500);
  }

  SERIAL_DIVIDER;
  USBSerial.println("LED Test done.");


  //-----------------------------------
  // GPIO
  //-----------------------------------
  SERIAL_DIVIDER;
  USBSerial.println("Starting GPIO Test."); 
  USBSerial.println("Each remaining exposed GPIO will flash n times, where n is the GPIO number.");
  USBSerial.println("Each flash will be 1ms HIGH and 1ms LOW.");
  USBSerial.println("Every 100ms the next pin is started.");
  USBSerial.println("This test will repeat forever without further commandline instructions"); 
}


//-----------------------------------------------------------------------------
//  loop
//-----------------------------------------------------------------------------
void loop() {

  //-----------------------------------
  // GPIO
  //-----------------------------------
  // Iterate through all pins
  for (int pin = 0; pin < NUMBER_GPIOS; pin++) {
    // Test only the ones enabled in the list
    if (gpios[pin]) {

      gpioStartTime = millis();

      // Blink for n cycles
      int cycle = 1;
      while (cycle <= pin) {
        digitalWrite(pin, HIGH);
        delay(1);
        digitalWrite(pin, LOW);
        delay(1);
        cycle++;
      }
      
      // wait for 100ms to be over
      delay(100 - (millis() - gpioStartTime));
      
    }
  }
  
}
