cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from submodule
# note: this must happen before project()
include("../pico-sdk/pico_sdk_init.cmake")

project(viking C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(VIKING_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})


# initialize the Raspberry Pi Pico SDK
pico_sdk_init()


if (NOT PICO_NO_HARDWARE)
    add_subdirectory(led)
    add_subdirectory("lcd/examples/AlpElectronixLogo")
    add_subdirectory("lcd/examples/vikingLVGL")
    add_subdirectory("io_expander/examples/Programmer")
    add_subdirectory(sd_card)
    add_subdirectory("libs/FatFS/FatFs_SPI" build)
    add_subdirectory("sd_card/examples/SDWrite")
    add_subdirectory(button)
    add_subdirectory(wifi)
    add_subdirectory("wifi/examples/wificonnection")
    add_subdirectory("libs/lvgl")
endif ()


add_library(vikingLcd INTERFACE)

target_sources(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lcd/core/vikingLcdDriver.c
)

target_include_directories(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lcd/core/
)

target_link_libraries(vikingLcd INTERFACE pico_stdlib )
