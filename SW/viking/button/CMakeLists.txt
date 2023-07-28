add_executable(Button
    main.c
)

target_link_libraries(Button PRIVATE pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(Button)

# add url via pico_set_program_url
example_auto_set_url(Button)
