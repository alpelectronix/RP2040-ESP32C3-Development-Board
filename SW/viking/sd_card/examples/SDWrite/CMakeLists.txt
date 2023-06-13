add_executable(SDWrite
    main.c
    hw_config.c
)

target_link_libraries(SDWrite PRIVATE sdCard pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(SDWrite)

# add url via pico_set_program_url
example_auto_set_url(SDWrite)
