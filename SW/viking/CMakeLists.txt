if (NOT PICO_NO_HARDWARE)
    add_subdirectory(led)
    add_subdirectory("lcd/examples/AlpElectronixLogo")
    add_subdirectory("lcd/examples/vikingLVGL")
    add_subdirectory("io_expander/examples/Programmer")
    add_subdirectory(sd_card)
    add_subdirectory("sd_card/lib/no-OS-FatFS-SD-SPI-RPi-Pico/FatFs_SPI" build)
    add_subdirectory("sd_card/examples/SDWrite")
    add_subdirectory(button)
    add_subdirectory(wifi)
    add_subdirectory("wifi/examples/wificonnection")
    add_subdirectory("libs/lvgl/")
endif ()


add_library(vikingLcd INTERFACE)

target_sources(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lcd/core/vikingLcdDriver.c
)

target_include_directories(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lcd/core/
)

target_link_libraries(vikingLcd INTERFACE pico_stdlib )
