# Building guide <!-- omit in toc -->

- [BOM](#bom)
    - [Bare / Prototype](#bare--prototype)
    - [ESP32 Internal Antenna](#esp32-internal-antenna)
    - [ESP32 External Antenna](#esp32-external-antenna)
    - [Raspberry Pi](#raspberry-pi)
- [3D printing](#3d-printing)
- [Assembling the boards](#assembling-the-boards)
- [Raspberry Pi specific subassembly](#raspberry-pi-specific-subassembly)
- [Firmware flash](#firmware-flash)
    - [ESP32](#esp32)
    - [Raspberry](#raspberry)

## BOM

### Bare / Prototype

| Name                        | Part number  | Amount | Link                                                                                                                                                    |
| :-------------------------- | :----------- | :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Protoboard PCB              | N/A          | 1      | [PCB](/pcb/Protoboard/FabricationFiles/Protoboard_Gerb.zip)                                                                                             |
| Connecting-piece PCB        | N/A          | 1      | [PCB](/pcb/Connecting-piece/FabricationOutputs/Connecting-piece_Gerb.zip)                                                                               |
| 8 x 2.54mm pin header       | N/A          | 1      | N/A                                                                                                                                                     |
| 10 x 2.54mm pin header      | N/A          | 1      | N/A                                                                                                                                                     |
| 3D printed case             | N/A          | 1      | [Case](/3d_printing/Bare.3mf)                                                                                                                           |
| M2 x 5mm self tapping screw | GB2670.2 5mm | 3      | [M2 x 5 noname screws](https://de.aliexpress.com/item/1005004325435136.html?spm=a2g0o.order_list.order_list_main.5.12bb5c5fFvie6I&gatewayAdapt=glo2deu) |

### ESP32 Internal Antenna

| Name                                          | Part number  | Amount | Link                                                                                                                                                    |
| :-------------------------------------------- | :----------- | :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------ |
| ESP32 PCB (With `ESP32-S2-WROVER`, `C701333`) | N/A          | 1      | [PCB](/pcb/ESP32/FabricationFiles/ESP32_Gerb.zip), [PCBA BOM](/pcb/ESP32/FabricationFiles/ESP32_Bom_InternalAntenna.csv)                                |
| Connecting-piece PCB                          | N/A          | 1      | [PCB](/pcb/Connecting-piece/FabricationOutputs/Connecting-piece_Gerb.zip)                                                                               |
| 8 x 2.54mm pin header                         | N/A          | 1      | N/A                                                                                                                                                     |
| 10 x 2.54mm pin header                        | N/A          | 1      | N/A                                                                                                                                                     |
| 3D printed case                               | N/A          | 1      | [Case](/3d_printing/ESP32_InternalAntenna.3mf)                                                                                                          |
| M2 x 5mm self tapping screw                   | GB2670.2 5mm | 3      | [M2 x 5 noname screws](https://de.aliexpress.com/item/1005004325435136.html?spm=a2g0o.order_list.order_list_main.5.12bb5c5fFvie6I&gatewayAdapt=glo2deu) |

### ESP32 External Antenna

| Name                                            | Part number  | Amount | Link                                                                                                                                                    |
| :---------------------------------------------- | :----------- | :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------ |
| ESP32 PCB (With `ESP32-S2-WROVER-I`, `C701334`) | N/A          | 1      | [PCB](/pcb/ESP32/FabricationFiles/ESP32_Gerb.zip), [PCBA BOM](/pcb/ESP32/FabricationFiles/ESP32_Bom_InternalAntenna.csv)                                |
| Connecting-piece PCB                            | N/A          | 1      | [PCB](/pcb/Connecting-piece/FabricationOutputs/Connecting-piece_Gerb.zip)                                                                               |
| 8 x 2.54mm pin header                           | N/A          | 1      | N/A                                                                                                                                                     |
| 10 x 2.54mm pin header                          | N/A          | 1      | N/A                                                                                                                                                     |
| 3D printed case                                 | N/A          | 1      | [Case](/3d_printing/ESP32_InternalAntenna.3mf)                                                                                                          |
| M2 x 5mm self tapping screw                     | GB2670.2 5mm | 3      | [M2 x 5 noname screws](https://de.aliexpress.com/item/1005004325435136.html?spm=a2g0o.order_list.order_list_main.5.12bb5c5fFvie6I&gatewayAdapt=glo2deu) |
| 2.4GHz Wifi Antenna with IPX to RP-SMA cable    | N/A          | 1      | [Noname Antenna](https://de.aliexpress.com/item/1005003489327360.html?spm=a2g0o.order_list.order_list_main.11.12bb5c5fFvie6I&gatewayAdapt=glo2deu)      |

### Raspberry Pi

| Name                                 | Part number     | Amount | Link                                                                                                                                                    |
| :----------------------------------- | :-------------- | :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Raspberry PCB                        | N/A             | 1      | [PCB](/pcb/Raspberry/FabricationFiles/Raspberry_Gerb.zip), [PCBA BOM](/pcb/Raspberry/FabricationFiles/Raspberry_Bom.csv)                                |
| Connecting-piece PCB                 | N/A             | 1      | [PCB](/pcb/Connecting-piece/FabricationOutputs/Connecting-piece_Gerb.zip)                                                                               |
| 8 x 2.54mm pin header                | N/A             | 1      | N/A                                                                                                                                                     |
| 10 x 2.54mm pin header               | N/A             | 1      | N/A                                                                                                                                                     |
| Raspberry Pi Zero W                  | RPD08818W       | 1      | [Elecrow Rpi Zero W](https://www.elecrow.com/raspberry-pi-zero-w.html)                                                                                  |
| 3D printed case                      | N/A             | 1      | [Case](/3d_printing/ESP32_InternalAntenna.3mf)                                                                                                          |
| M2 x 5mm self tapping screw          | GB2670.2 5mm    | 3      | [M2 x 5 noname screws](https://de.aliexpress.com/item/1005004325435136.html?spm=a2g0o.order_list.order_list_main.5.12bb5c5fFvie6I&gatewayAdapt=glo2deu) |
| M2.5 Hexagon Nut                     | DIN-EN-ISO 4032 | 2      | [Norm](https://www.fasteners.eu/standards/ISO/4032/)                                                                                                    |
| M2.5 x 6mm countersunk machine screw | ISO 14581       | 2      | [Norm](https://www.fasteners.eu/standards/ISO/14581/)                                                                                                   |
| CR927 (3V) Battery                   | N/A             | 1      | N/A                                                                                                                                                     |

## 3D printing

In the [3d_printing](/3d_printing/) folder you'll find a case option for every design variant. The cases are to be printed with PETG with 0.15mm layer height and a 0.4mm nozzle. Larger layer heights or nozzles might make the boards not fit easily.

The cases currently provided are:

- Bare (Case without cutouts for prototyping)
- ESP32_InternalAntenna (Wifi dev board using the on-board ESP32 antenna. Sleek and compact)
- ESP32_ExternalAntenna (Wifi dev board using an external antenna. Powerful but bulky)
- Raspberry (Pi Zero mount)

## Assembling the boards

**Step 1 - Clamp the back board vertically**

![Step1](/img/Manual_step1.jpg)

**Step 2 - Slide on the connecting piece**

![Step2](/img/Manual_step2.jpg)

**Step 3 - Solder down one of the connectors**

You don't have to care about the angle of the boards for now.

![Step3](/img/Manual_step3.jpg)

**Step 4 - Reflow the connection, aligning the boards at 90 degrees**

![Step](/img/Manual_step4.jpg)

**Step 5 - Make sure the boards are also aligned when viewed from the front**

![Step5](/img/Manual_step5.jpg)

**Step 6 - Solder the remaining connections on the top**

![Step6](/img/Manual_step6.jpg)

**Step 7 - Make sure that none of the connections are bridged between the pads horizontally**

![Step7](/img/Manual_step7.jpg)

**Step 8 - Flip the board around so you can see the bottom connections**

![Step8](/img/Manual_step8.jpg)

**Step 9 - Solder the bottom connections**

![Step9](/img/Manual_step9.jpg)

**Step 10 - Flip the board around again and solder the pin headers**

Make sure to get them at a right angle to the board as well. Otherwise you will put stress on the board when inserting into the Flipper.

![Step10](/img/Manual_step10.jpg)

**Step 11 - Optional - Find the 3D printed case and screws**

![Step11](/img/Manual_step11.jpg)

<details>
<summary markdown="span">Excursion: Installing the antenna jack for external antenna boards</summary>

**Step 11.1 - Insert the antenna jack into the slot and fix nut from the outside**

![Step11.1](/img/Manual_step11_1.jpg)

![Step11.1b](/img/Manual_step11_1b.jpg)

**Step 11.2 - Plug antenna extension into the board**

![Step11.2](/img/Manual_step11_2.jpg)

**Step 11.3 - Carefully route the extension while inserting the board**

![Step11.3](/img/Manual_step11_3.jpg)

**Step 11.4 - Make sure the board is seated without pinching the wire**

![Step11.4](/img/Manual_step11_4.jpg)

</details>

**Step 12 - Slide the board into the case and screw down the 3 mounting points**

![Step12](/img/Manual_step12.jpg)

## Raspberry Pi specific subassembly

**Step 0 - Find the Raspberry board and read the instructions as printed on the board**

![Step0](/img/Manual_Rpi_step0.jpg)

**Step 1 - Place the Raspberry Pi Zero W on top of the board**

Note the lack of pin headers. The board won't fit with headers installed!

![Step1](/img/Manual_Rpi_step1.jpg)

**Step 2 - Screw down the Raspberry Pi Zero W using M2.5 screws and nuts from behind**

The screws are countersunk into the PCB so they will be flat from the outside

![Step2](/img/Manual_Rpi_step2.jpg)

**Step 3 - Solder the 7 connections through both boards**

With the Pi face down, heat the pads from the backpack board and apply solder into the hole. You will see the solder "bubble down" through both holes forming a connection between the boards.

Flipping the board to the front you should see solder ran all the way through both boards. This picture shows 50% of the solder process done, having soldered only from the back:

![Step3](/img/Manual_Rpi_step3.jpg)

When it looks like this, apply some solder from the top as well to make the connections look nice from both sides.

**Step 4 - The finished board should look like this**

You should now see clean connections between both sides of the board. You can now insert the CR927 battery for the RTC if desired, and continue with the rest of the general build guide, to assemble your backpack.

![Step4](/img/Manual_Rpi_step4.jpg)

## Firmware flash

### ESP32

I recommend using [FZEasyMarauderFlash](https://github.com/SkeletonMan03/FZEasyMarauderFlash) for this. It allows you to flash either the BlackMagic Firmware that Flipper itself ships with their Devboards, as well as Marauder or Evil Portal.

### Raspberry

TBD
