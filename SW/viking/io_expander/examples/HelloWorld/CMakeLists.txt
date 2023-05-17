add_executable(HelloWorld
    main.c
)

target_link_libraries(HelloWorld PRIVATE SLG46826 hardware_pwm hardware_uart hardware_spi hardware_i2c hardware_dma hardware_pio hardware_interp hardware_timer hardware_watchdog hardware_clocks)

# create map/bin/hex file etc.
pico_add_extra_outputs(HelloWorld)

# add url via pico_set_program_url
example_auto_set_url(HelloWorld)

