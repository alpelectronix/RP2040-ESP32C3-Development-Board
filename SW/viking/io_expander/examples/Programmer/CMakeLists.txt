add_executable(Programmer
    main.c
)

target_link_libraries(Programmer PRIVATE pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(Programmer)

# add url via pico_set_program_url
#example_auto_set_url(Programmer)

