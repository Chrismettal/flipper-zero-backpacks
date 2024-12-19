# Flipper Zero Backpacks <!-- omit in toc -->

[![License: CC BY-SA 4.0](https://img.shields.io/badge/license-CC%20BY--SA%204.0-blue?style=flat-square)](https://creativecommons.org/licenses/by-sa/4.0/)
[![Shop: Elecrow](https://img.shields.io/badge/shop-Elecrow-blue?style=flat-square)](https://www.elecrow.com/store/Binary-6)
[![Donations: Coffee](https://img.shields.io/badge/donations-Coffee-brown?style=flat-square)](https://github.com/Chrismettal#donations)

![NiceBack](/img/NiceBack.jpg)

This is a collection of addon boards for the [Flipper Zero](https://flipperzero.one/) multi-tool in the style of a backpack that clips behind the Flipper!

Right now it features only an ESP32 wifi board, like the official wifi devboard, only formatted as a backpack and with an SD card slot fitted. There is also a protoboard to create your own designs in the same formfactor.

The backpack framework is designed to fit snugly to a Flipper inside its silicone case. Without a silicone sleeve, the board will have 2mm of space around the Flipper, which might be undesireable.

![FrontNoFlipper](/img/FrontNoFlipper.png)

Finished boards are currently stocked at [Elecrow](https://www.elecrow.com/store/Binary-6).

[![ElecrowBadge](/img/Elecrow.png)](https://www.elecrow.com/store/Binary-6)

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## Table of contents <!-- omit in toc -->

- [Boards](#boards)
  - [Connecting piece](#connecting-piece)
  - [ESP32 Wifi Dev board](#esp32-wifi-dev-board)
    - [Firmware](#firmware)
    - [Internal / External Antenna](#internal--external-antenna)
    - [SD Card](#sd-card)
  - [Protoboard](#protoboard)
  - [Raspberry Pi Zero W](#raspberry-pi-zero-w)
  - [Taylor Stahl - Mayhem](#taylor-stahl---mayhem)
- [Making your own](#making-your-own)
- [3D Printing](#3d-printing)
- [Building guide](#building-guide)
- [Sources](#sources)
- [Donations](#donations)
- [License](#license)

## Boards

All boards use `1mm board thickness` unless otherwise specified.

### Connecting piece

![ConnectingPiece](img/ConnectingPiece.png)

Every board uses the same connector up top. This is what plugs into the Flipper and makes the board an actual backpack.
The addon board and the connecting piece slide into each other and get soldered at the intersection to form a solid, right angle connection.

### ESP32 Wifi Dev board

![Wifi](img/NiceBack.jpg)

[**Buy on Elecrow**](https://www.elecrow.com/flipper-zero-wifi-backpack-esp32.html)

Very similar to the [official Wifi dev board](https://shop.flipperzero.one/collections/flipper-zero-accessories/products/wifi-devboard). Additionally includes a micro SD card slot so you don't have to mod the official board yourself. 

Other than that all guides applicable to the official Wifi dev board are also applicable here.

In this repo, there are 3D files for boards with the internal, as well as the external antenna available. The board is the same between the two, only the part number of the ESP changes.

#### Firmware

The board ships with the [Black Magic debugger firmware](https://black-magic.org/), just like the official board. Alternatively you can use an alternate firmware like the [ESP32 Marauder](https://github.com/justcallmekoko/ESP32Marauder/wiki/flipper-zero) by [JustCallMeKoko](https://github.com/justcallmekoko) if you want to get spicy.

**Every firmware that works on the [official dev board](https://shop.flipperzero.one/collections/flipper-zero-accessories/products/wifi-devboard) should also work on this backpack**

#### Internal / External Antenna

The ESP32-S2 part number referenced in the BOM ([C701334](https://www.lcsc.com/product-detail/WiFi-Modules_Espressif-Systems-ESP32-S2-WROVER-I-N4R2_C701334.html)) leads to an `-I` version of the ESP32-S2, which has the antenna plug mounted on the ESP. Versions without the `-I` in the product name do not have the antenna plug mounted. Next to the antenna plug is a small jumper that is set accordingly, to use either the internal PCB antenna, or the external plug antenna.

By default, `-I` ESPs have the jumper set to use an external antenna via the plug. 

**If you use a non `-I` variant of the ESP32-S2, like the boards found in the shop, you would have to mount an antenna plug before being able to use the external antenna**

**if you use an `-I` ESP32-S2 you would need to move the jumper over to use the internal antenna!**

#### SD Card

The ESP seems to be pretty restrictive in SD Card compatibility especially when running Marauder. This is not a limitation of this specific design but inherent to the ESP32. I've had luck with older and smaller SD cards sub 16 GB and Class 10 at max. OLDER `Sandisk Ultra Micro SDHC I` seem to work pretty well when formatted to `FAT32`.

### Protoboard

![Protoboard](/img/ProtoNiceTop.jpg)

A simple `2.54mm` pitch protoboard backpack, fitting the same case as the ESP32 board. While it is through hole, beware that there isn't much space between the Flippers silicone case and the board, so make sure to only put taller components on the side facing away from the flipper, and stay pretty flat when wiring on the bottom side. Also remember that the bottom side will be somewhat exposed, so you should consider placing and wiring mostly on the encased side.

### Raspberry Pi Zero W

![Raspberry](/img/RpiNiceBack.jpg)

This is an adapter to supply and connect a Raspberry Pi Zero W to the Flipper via UART.

The board was mainly created for the [Flippagotchi](https://github.com/Matt-London/pwnagotchi-flipper) app, which renders a [Pwnagotchi](https://pwnagotchi.ai/)`s screen onto the flipper.

Additionally, the board includes a `PCF8523` realtime clock so your Pwnagotchi actually knows what time it is. The battery used for the RTC is a `CR927`.

To set up the Realtime clock, you can follow the guide on the [Pwnagotchi docs](https://pwnagotchi.ai/configuration/#connecting-to-pi0w-with-microusb-cable-on-linux-host) as well as [Adafruit](https://learn.adafruit.com/adding-a-real-time-clock-to-raspberry-pi/set-rtc-time).

If you don't want to connect your pwnagotchi to the internet, you can always set its time with `'sudo date -s 'YYYY-MM-DD HH:MM:SS'` , before writing the Raspberry's time the RTC with `sudo hwclock -w`

### Taylor Stahl - Mayhem

![Mayhem](/img/TaylorStahlsMayhem.png)

This is a [Flipper Zero Mayhem](https://github.com/eried/flipperzero-mayhem) backpack created by [Taylor Stahls](taylor.stahls@gmail.com) done with EasyEDA.

It uses the same backpack connector as the other boards found here to implement an ESP32-CAM, CC1101 and NRF24 in a backpack format. A switch was added to choose between the CC1101 and the NRF24 being active.

I personally haven't yet played around with this board, as Taylor merely asked me to add his board to this repo to respect the original license. Taylor is currently setting up his own Tindie shop to sell his Mayhem boards eventually. Link to be added once public.

## Making your own

All files to order your own boards from existing designs can be found under `/pcb/<BoardName>/FabricationFiles`. This includes Gerbers as well as BOMs for PCBA so the boards arrive fully built. All files were exported to be ordered at JLCPCB and use LCSC part numbers.

**All boards need to be ordered as 1mm thickness so they fit together well!**

There is also a clean KiCad project under `/pcb/Clean/` to create original designs. If you end up creating your own design I would love to merge your fork into this repo!

## 3D Printing

A 3D printable case project is included in `/3d_printing/flipper-zero-backpacks.FCStd`.

You can use [FreeCAD](https://www.freecad.org/) to open and modify it. 

A `bare` version, as well as one fitting the `ESP32` board have been exported as `.step` and `.3mf` files into `/3d_printing/`.

The cases can be printed without any supports and are best printed in PETG, but there is no reason why PLA wouldn't be sufficient.

## Building guide

Please head over to [the building guide document](/Guide/README.md)!

## Sources

- [ESP32-S2-WROVER step file](https://grabcad.com/library/esp32-s2-wrover-1)

## Donations

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## License

 <a rel="CClicense" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
