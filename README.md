# PCInfo

## Overview 

PCInfo was made for sending data about hardware like temperature, fan RPM etc. to STM32 vis USB and displaing it on the screen.

## Description

* Computer side:
```
Requirements: Windows with .NET Framework 3.0 or higher. 
```
Windows Presentation Foundation application, which allows us to manage serial ports and sending data using Virtual COM Port.
Data is sending every one second. 

* STM32 side:

## Tools

* Visual Studio 2017
* Keil uVision 5.25.2.0
* Virtual COM Port 
* OpenHardwareMonitor library - https://github.com/openhardwaremonitor/openhardwaremonitor

## How to run

Run WpfApp1, choose the right port and click "Wyslij dane".

## How to compile

Download repository and compile

## Future improvements

Sending data from Linux

## Attributions 

Virtual COM Port - https://github.com/xenovacivus/STM32DiscoveryVCP
OpenHardwareMonitor library - https://github.com/openhardwaremonitor/openhardwaremonitor

## License

MIT

## Credits

Adam Olszewski & Rafał Adamski

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Marek Kraft/Michał Fularz/Tomasz Mańkowski/Adam Bondyra
