# Flipper Zero Backpacks <!-- omit in toc -->

[![License: CC BY-SA 4.0](https://img.shields.io/badge/license-CC%20BY--SA%204.0-blue?style=flat-square)](https://creativecommons.org/licenses/by-sa/4.0/)
[![Shop: Tindie](https://img.shields.io/badge/shop-Tindie-blue?style=flat-square)](https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium)
[![Donations: Coffee](https://img.shields.io/badge/donations-Coffee-brown?style=flat-square)](https://github.com/Chrismettal#donations)

![BackCase](/img/BackCaseWifi.png)

This is a collection of addon boards for the [Flipper Zero](https://flipperzero.one/) multi-tool in the style of a backpack that clips behind the Flipper!

Right now it features only an ESP32 wifi board, like the official wifi devboard, only formatted as a backpack and with an SD card slot fitted.
As soon as this board is verified (currently in production) protoboards and other addons will be created in the same form factor!

The backpack framework is designed to fit snugly to a Flipper inside its silicone case. Without a silicone sleeve, the board will have 2mm of space around the Flipper, which might be undesireable.

![FrontNoFlipper](img/FrontNoFlipper.png)

Finished designs will be stocked at Tindie.
The first prototype run will be quite limited but if there is interest in more, a bigger batch will be produced.

<a href="https://www.tindie.com/stores/binary-6/?ref=offsite_badges&utm_source=sellers_Chrismettal&utm_medium=badges&utm_campaign=badge_medium"><img src="https://d2ss6ovg47m0r5.cloudfront.net/badges/tindie-mediums.png" alt="I sell on Tindie" width="150" height="78"></a>

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## Table of contents <!-- omit in toc -->

- [Boards](#boards)
  - [Connecting piece](#connecting-piece)
  - [ESP32 Wifi Dev board](#esp32-wifi-dev-board)
    - [Firmware](#firmware)
    - [Internal / External Antenna](#internal--external-antenna)
  - [Protoboard](#protoboard)
- [3D Printing](#3d-printing)
- [Building guide](#building-guide)
  - [Step 1 - Clamp the back board vertically](#step-1---clamp-the-back-board-vertically)
  - [Step 2 - Slide on the connecting piece](#step-2---slide-on-the-connecting-piece)
  - [Step 3 - Solder down one of the connectors](#step-3---solder-down-one-of-the-connectors)
  - [Step 4 - Reflow the connection, aligning the boards at 90 degrees](#step-4---reflow-the-connection-aligning-the-boards-at-90-degrees)
  - [Step 5 - Make sure the boards are also aligned when viewed from the front](#step-5---make-sure-the-boards-are-also-aligned-when-viewed-from-the-front)
  - [Step 6 - Solder the remaining connections on the top](#step-6---solder-the-remaining-connections-on-the-top)
  - [Step 7 - Make sure that none of the connections are bridged between the pads horizontally](#step-7---make-sure-that-none-of-the-connections-are-bridged-between-the-pads-horizontally)
  - [Step 8 - Flip the board around so you can see the bottom connections](#step-8---flip-the-board-around-so-you-can-see-the-bottom-connections)
  - [Step 9 - Solder the bottom connections](#step-9---solder-the-bottom-connections)
  - [Step 10 - Flip the board around again and solder the pin headers](#step-10---flip-the-board-around-again-and-solder-the-pin-headers)
  - [Step 11 - Optional - Find the 3D printed case and screws](#step-11---optional---find-the-3d-printed-case-and-screws)
  - [Step 12 - Slide the board into the case and screw down the 3 mounting points](#step-12---slide-the-board-into-the-case-and-screw-down-the-3-mounting-points)
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

Very similar to the [official WiFi dev board](https://shop.flipperzero.one/collections/flipper-zero-accessories/products/wifi-devboard). Additionally includes a micro SD card slot so you don't have to mod the official board yourself. Currently in production, to be stocked at [Tindie](https://www.tindie.com/stores/binary-6/) soon after production finished.

#### Firmware

The board ships with the [Black Magic debugger firmware](https://black-magic.org/), just like the official board. Alternatively you can use an alternate firmware like the [ESP32 Marauder](https://github.com/justcallmekoko/ESP32Marauder/wiki/flipper-zero) by [JustCallMeKoko](https://github.com/justcallmekoko) if you want to get spicy.

**Every firmware that works on the [official dev board](https://shop.flipperzero.one/collections/flipper-zero-accessories/products/wifi-devboard) should also work on this backpack**

#### Internal / External Antenna

The ESP32-S2 part number referenced in the BOM ([C701334](https://www.lcsc.com/product-detail/WiFi-Modules_Espressif-Systems-ESP32-S2-WROVER-I-N4R2_C701334.html)) leads to an `-I` version of the ESP32-S2, which has the antenna plug mounted on the ESP. Versions without the `-I` in the product name do not have the antenna plug mounted. Next to the antenna plug is a small jumper that is set accordingly, to use either the internal PCB antenna, or the external plug antenna.

By default, `-I` ESPs have the jumper set to use an external antenna via the plug. 

**If you use a non `-I` variant of the ESP32-S2, like the boards found in the shop, you would have to mount an antenna plug before being able to use the external antenna**

**if you use an `-I` ESP32-S2 you would need to move the jumper over to use the internal antenna!**

### Protoboard

![Protoboard](/img/ProtoNiceTop.jpg)

A simple `2.54mm` pitch protoboard backpack, fitting the same case as the ESP32 board. While it is through hole, beware that there isn't much space between the Flippers silicone case and the board, so make sure to only put taller components on the side facing away from the flipper, and stay pretty flat when wiring on the bottom side. Also remember that the bottom side will be somewhat exposed, so you should consider placing and wiring mostly on the encased side.

## 3D Printing

A 3D printable case project is included in `/3d_printing/flipper-zero-backpacks.FCStd`.

You can use [FreeCAD](https://www.freecad.org/) to open and modify it. 

A `bare` version, as well as one fitting the `ESP32` board have been exported as `.step` and `.3mf` files and are also uploaded to [Printables](https://www.printables.com/@ChrismettalBinary6/models).

The cases can be printed without any supports and are best printed in PETG, but there is no reason why PLA wouldn't be sufficient.

## Building guide

<details>
  <summary markdown="span">Detailed build guide - click to expand</summary>

  ### Step 1 - Clamp the back board vertically

  ![Step1](/img/Manual_step1.jpg)

  ### Step 2 - Slide on the connecting piece

  ![Step2](/img/Manual_step2.jpg)

  ### Step 3 - Solder down one of the connectors

  You don't have to care about the angle of the boards for now.

  ![Step3](/img/Manual_step3.jpg)

  ### Step 4 - Reflow the connection, aligning the boards at 90 degrees

  ![Step](/img/Manual_step4.jpg)

  ### Step 5 - Make sure the boards are also aligned when viewed from the front

  ![Step5](/img/Manual_step5.jpg)

  ### Step 6 - Solder the remaining connections on the top

  ![Step6](/img/Manual_step6.jpg)

  ### Step 7 - Make sure that none of the connections are bridged between the pads horizontally

  ![Step7](/img/Manual_step7.jpg)

  ### Step 8 - Flip the board around so you can see the bottom connections

  ![Step8](/img/Manual_step8.jpg)

  ### Step 9 - Solder the bottom connections

  ![Step9](/img/Manual_step9.jpg)

  ### Step 10 - Flip the board around again and solder the pin headers

  Make sure to get them at a right angle to the board as well. Otherwise you will put stress on the board when inserting into the Flipper.

  ![Step10](/img/Manual_step10jpg)

  ### Step 11 - Optional - Find the 3D printed case and screws

  ![Step11](/img/Manual_step11.jpg)

  ### Step 12 - Slide the board into the case and screw down the 3 mounting points

  ![Step12](/img/Manual_step12.jpg)

</details>

## Sources

- [ESP32-S2-WROVER step file](https://grabcad.com/library/esp32-s2-wrover-1)

## Donations

**If you like my work please consider [supporting my caffeine addiction](https://github.com/Chrismettal#donations)!**

## License

 <a rel="CClicense" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
