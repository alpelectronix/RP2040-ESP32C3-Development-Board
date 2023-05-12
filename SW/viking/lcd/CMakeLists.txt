add_library(vikingLcd INTERFACE)

target_sources(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/core/vikingLcdDriver.c
)

target_include_directories(vikingLcd INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/core/
)

target_link_libraries(vikingLcd INTERFACE pico_stdlib )