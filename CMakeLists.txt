cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(ym2413_player)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project



add_executable(ym2413_player 
	src/main.c
)

pico_generate_pio_header(ym2413_player 
	${CMAKE_CURRENT_LIST_DIR}/src/ym2413_io.pio
)

target_link_libraries(ym2413_player 
	pico_stdlib
	
	hardware_pio
	hardware_i2c
)

pico_enable_stdio_usb(ym2413_player 1)
pico_enable_stdio_uart(ym2413_player 0)

pico_add_extra_outputs(ym2413_player)
