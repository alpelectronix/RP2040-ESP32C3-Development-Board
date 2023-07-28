add_executable(VikingLVGL
    main.c
)


target_link_libraries(VikingLVGL PRIVATE vikingLcd hardware_pwm lvgl pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(VikingLVGL)

# add url via pico_set_program_url
example_auto_set_url(VikingLVGL)



