add_executable(vikingLVGL
    main.c
)


target_link_libraries(vikingLVGL PRIVATE vikingLcd hardware_pwm lvgl pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(vikingLVGL)

# add url via pico_set_program_url
example_auto_set_url(vikingLVGL)



