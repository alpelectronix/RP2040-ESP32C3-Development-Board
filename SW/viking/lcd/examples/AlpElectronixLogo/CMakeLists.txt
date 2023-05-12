add_executable(AlpElectronixLogo
    main.c
)


target_link_libraries(AlpElectronixLogo PRIVATE vikingLcd hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(AlpElectronixLogo)

# add url via pico_set_program_url
example_auto_set_url(AlpElectronixLogo)
