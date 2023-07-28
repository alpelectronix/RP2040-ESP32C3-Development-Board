add_executable(WiFiConnection
    main.c
)


target_link_libraries(WiFiConnection PRIVATE vikingLcd hardware_pwm lvgl pico_stdlib hardware_uart)

# create map/bin/hex file etc.
pico_add_extra_outputs(WiFiConnection)

# add url via pico_set_program_url
example_auto_set_url(WiFiConnection)



