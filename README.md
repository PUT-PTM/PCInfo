# PCInfo

## Overview 

PCInfo was made for sending data about hardware like temperature, fan RPM etc. to STM32 vis USB and displaying it on the screen.

## Description

* Computer side:
```
Requirements: Windows with .NET Framework 3.0 or higher. 
```
Windows Presentation Foundation application, which allows us to manage serial ports and sending data using Virtual COM Port.
Data is sending every one second. 

* STM32 side:
After plugging to a PC, our project will start displaying "Welcome screen", until you will send him data from the computer. You can choose data to display by pushing the encoder button, and rotate it. When you finally decide, push button again to choose what to display on the lower row. After setting the 4th row microcontroller will return to display and refreshing you data.

## Tools

* Visual Studio 2017
* Keil uVision 5.25.2.0
* Virtual COM Port 
* OpenHardwareMonitor library - https://github.com/openhardwaremonitor/openhardwaremonitor
* STM
* OLED Display (0,95'' 96x64px favorable)
* Encoder with button

## How to run

Plug your microcontroller to your PC. Run SerialPortWPF.exe as administrator, choose the right port and click "Wyslij dane". After that STM will soon display live data.

## How to compile

Download repository, compile and upload to your MC.

## Future improvements

Sending data from Linux

## Attributions 

* Virtual COM Port - https://github.com/xenovacivus/STM32DiscoveryVCP
* OpenHardwareMonitor library - https://github.com/openhardwaremonitor/openhardwaremonitor
* Modified SSD1331 library for OLED Display - https://github.com/adafruit/Adafruit-SSD1331-OLED-Driver-Library-for-Arduino

## License

MIT

## Credits

Adam Olszewski & Rafał Adamski

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Marek Kraft/Michał Fularz/Tomasz Mańkowski/Adam Bondyra
