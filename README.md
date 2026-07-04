# pico_thrust
A UART to PWM bridge for controlling ESCs that is a replacement for the micropython implementation residing in `AUV`.

## Features (Planned)
- Compatible with PPSTI, like the current microython implementation
- Built in inactivity detection
- High reliability


## Compilation

### Install Dependencies
	sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
### Get the Pico SDK
	git clone --depth 1 https://github.com/raspberrypi/pico-sdk.git
	cd pico-sdk
	git submodule update --init
	cd ..
	
### Build
	mkdir build
	cd build
	cmake -DPICO_BOARD=<board> ..

### Common Board Names
- Pico `pico`
- Pico 2 `pico2`
- Pico W `pico_w`
- Pico 2 W `pico2_w`
