# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "C:/Users/Caner/Documents/Pico/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")



# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(RP2040-ESP32C3_Dev_Board C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(RP2040-ESP32C3_Dev_Board RP2040-ESP32C3_Dev_Board.c )

pico_set_program_name(RP2040-ESP32C3_Dev_Board "RP2040-ESP32C3_Dev_Board")
pico_set_program_version(RP2040-ESP32C3_Dev_Board "0.1")

pico_enable_stdio_uart(RP2040-ESP32C3_Dev_Board 0)
pico_enable_stdio_usb(RP2040-ESP32C3_Dev_Board 1)

add_subdirectory(SLG46826)

# Peripherals depend on pico_stdlib only.
#target_link_libraries(SLG46826 PUBLIC pico_stdlib)

# Peripherals depend on pico_stdlib only.
#target_link_libraries(HAL_SLG46826 PUBLIC pico_stdlib)

# Add the standard library to the build
target_link_libraries(RP2040-ESP32C3_Dev_Board
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(RP2040-ESP32C3_Dev_Board PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)



# Add any user requested libraries
target_link_libraries(RP2040-ESP32C3_Dev_Board
        hardware_spi
        hardware_i2c
        hardware_dma
        hardware_pio
        hardware_interp
        hardware_timer
        hardware_watchdog
        hardware_clocks
        SLG46826
        HAL_SLG46826
        )

pico_add_extra_outputs(RP2040-ESP32C3_Dev_Board)

