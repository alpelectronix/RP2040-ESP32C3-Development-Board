add_executable(led_blink
        main.c
        )

# pull in common dependencies
target_link_libraries(led_blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(led_blink)

# add url via pico_set_program_url
example_auto_set_url(led_blink)
