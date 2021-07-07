# STM32F411 Black Pill

This repository is based on this one [here](https://github.com/ahessling/STM32F4Template) but is customized for the
STM32F411CE / Black Pill.

## About

This repository contains a CMake-based template project as a starting point for STM32 F4 projects. ST's official
Standard Peripheral Library is already included in this repository.

Both C and C++ sources are supported. CMake will also try to find OpenOCD and will generate a flash target for easy
programming of the microcontroller.

This template includes a sample application which turns on the blue LED on the STM32F4 Black Pill board for
demonstration purposes.

## Quick start

You can run the `tools/setup.sh` script in order to install all required software.

Then you can run the following commands,

```
mkdir build
cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../CMake/GNU-ARM-Toolchain.cmake ..
cd build 
make
st-flash write src/STM32F4Template.bin 0x8000000
```

## Other STM32

In the `./CMakeLists.txt` change these parameters to your need,

```
# STM32-specific settings
set(DEVICE_FAMILY STM32F411xE)

# Speed of external resonator
set(HSE_VALUE 25000000)

# Used linker file (just for testing)
get_filename_component(LINKER_SCRIPT linker/STM32F411CE_FLASH.ld ABSOLUTE)
```

I would advise you to copy the `startup_xxx.s` file corresponding to your mcu in the `./src` folder. Be careful to use
the correct linker script as well. The OpenOCD config `./tools/stm32f4.cfg` is working for stm32f4 with st-link v2.