if (NOT PICO_NO_HARDWARE)
    add_subdirectory(led_blink)
    add_subdirectory(lcd)
    add_subdirectory("lcd/examples/AlpElectronixLogo")
    add_subdirectory(io_expander)
    add_subdirectory("io_expander/examples/HelloWorld")
endif ()

