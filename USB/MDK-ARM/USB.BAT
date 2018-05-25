SET PATH=D:\KEIL MDKARM5\ARM\ARMCC\Bin;C:\ProgramData\Oracle\Java\javapath;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\dotnet\;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;D:\CoIDE\gcc\bin;C:\WINDOWS\System32\OpenSSH\;C:\Users\Rafal\AppData\Local\Microsoft\WindowsApps;D:\Nmap;C:\Users\Rafal\AppData\Local\GitHubDesktop\bin;%USERPROFILE%\AppData\Local\Microsoft\WindowsApps;D:\Todo Backup\bin\x64\
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F407VGTx
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=USB
SET CPU_CLOCK=0x0501BD00
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmAsm" --Via "usb\startup_stm32f407xx._ia"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_conf.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_msp.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_cdc_if.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_desc.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usb_device.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\main.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_it.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\ssd1331.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\fonts.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\system_stm32f4xx.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_core.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_cdc.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_ioreq.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\usbd_ctlreq.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_ll_usb.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_pcd.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_flash_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_gpio.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_flash.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_pcd_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_pwr.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_dma_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_rcc_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_tim.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_rcc.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_pwr_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_tim_ex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_dma.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_flash_ramfunc.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_cortex.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmCC" --Via "usb\stm32f4xx_hal_spi.__i"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\ArmLink" --Via "USB\USB.lnp"
"D:\KEIL MDKARM5\ARM\ARMCC\Bin\fromelf.exe" "USB\USB.axf" --i32combined --output "USB\USB.hex"
