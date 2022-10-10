
This repository contains the source code to build the firmware for the NanoVNA V2 (S-A-A-2).

See https://nanorfe.com/nanovna-v2.html for more info.

Developers chat room: https://discord.gg/DUH5Xk5

Below is information for building the firmware on Linux.

## Installing the compiler

### Debian based systems

On any recent Debian based installation:
``` 
sudo apt install gcc-arm-none-eabi
```

### Installing the upstream toolchain

If you want to install the latest version of the gnu ARM toolchain:

1. get the latest version from https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads . You can download it using your browser or a command line tool like `wget`:
```
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2020q2/gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2
```

2. untar it, eg. in `/opt/toolchains`:
```
sudo mkdir -p /opt/toolchains
sudo tar xvf -C /opt/toolchains gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2
```

3. set your PATH environment variable:
```
export PATH=/opt/toolchains/gcc-arm-none-eabi-9-2020-q2-update/bin:$PATH
```

## Installing dependencies

To upload the firmware on the NanoVNA2, you will need:

- Python 3
- [pyserial](https://github.com/pyserial/pyserial)

On a Debian based system, you can use:

```
sudo apt install python3-serial
```

## Getting the source code

The code is spread out over 3 repositories, 2 of which are submodules of the main NanoVNA-V2-firmware one:
Questo copia il branch giusto.
```
git clone --branch 20201013 https://github.com/nanovna/NanoVNA-V2-firmware.git
//OLD git clone --recursive https://github.com/nanovna/NanoVNA-V2-firmware.git
cd NanoVNA-V2-firmware
```

##Aggiornamento Bootloader
Conviene aggiornare il bootloader
git checkout -- gd32f303cc_with_bootloader.ld

### Download 
gh repo clone nanovna/libopencm3-gd32f3

-Change the file  with texteditor 'NanoVNA-V2-firmware/libopencm3/Makefile' replace row 27 with:
SRCLIBDIR:= $(subst $(space),$(space),$(realpath lib))

##Controlli preliminari
-Verificare che la cartelle sotto 'NanoVNA-V2-firmware/' 'libopencm3' e 'mculib' ci siano dei file.

-Verificare che il file 'NanoVNA-V2-firmware/libopencm3/Makefile' alla riga 27 ci sia questa stringa:
SRCLIBDIR:= $(subst $(space),$(space),$(realpath lib))

-Verificare che sia installo Python sotto /usr/bin/env altrimenti il compilatore restituirà '/usr/ /env: ‘python’: No such file directory bin or'
 Soluzione 1: apt -get install python3
 Soluzione 2: 'whareis python3' e 'sudo ln -s /usr/bin/python3 /usr/bin/python'

## Building
Now you can build the firmware by running make in the firmware sources directory:
Se si ricompila bisogna prima cancellare i file nella directory 'NanoVNA-V2-firmware/' i 'binary.bin','binary.elf' e 'binary.hex'
```
cd NanoVNA-V2-firmware
make BOARDNAME=board_v2_2 EXTRA_CFLAGS="-DSWEEP_POINTS_MAX=201 -DSAVEAREA_MAX=7"
```

Non testato:
```
make -j4 BOARDNAME=board_v2_2 EXTRA_CFLAGS="-DSWEEP_POINTS_MAX=201 -DSAVEAREA_MAX=7" LDSCRIPT=./gd32f303cc_with_bootloader.ld

```

## Flashing the firmware
There are two options to update the firmware when using the regular USB interface:
 - Use NanoVNA-QT
 - Command line
For this to work the device must stay in the bootloader and enter _DFU mode_

Another option is using a debugger using the debug pins.

### Entering DFU mode
```
Switch the device off
Press and hold down the left button (the one closest to the Port 1 or the On/Off switch)
Switch the device on (screen stays white), release the button
```
