add_executable(Led
        main.c
        )

# pull in common dependencies
target_link_libraries(Led pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(Led)

# add url via pico_set_program_url
example_auto_set_url(Led)
