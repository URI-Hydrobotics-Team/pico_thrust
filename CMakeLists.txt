# invoke using: mkdir -p build && cd build && cmake .. -DPICO_BOARD=pico2 -DPICO_SDK_PATH=${HOME}/Downloads/pico-sdk/ -DPICO_TOOLCHAIN_PATH=/Applications/ArmGNUToolchain/15.2.rel1/arm-none-eabi/bin/ && cd ..

cmake_minimum_required(VERSION 3.13)

# initialize the SDK directly
include(pico-sdk/pico_sdk_init.cmake)

# note CXX is only necessary for new_delete.cpp in pico_runtime
project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()



# rest of your project
add_executable(pico_thrust
	main.c
)

# pull in common dependencies
target_link_libraries(pico_thrust pico_stdlib hardware_pwm)

# create map/bin/hex/uf2 file in addition to ELF.

pico_enable_stdio_usb(pico_thrust 1)
pico_enable_stdio_uart(pico_thrust 0)
pico_add_extra_outputs(pico_thrust)
