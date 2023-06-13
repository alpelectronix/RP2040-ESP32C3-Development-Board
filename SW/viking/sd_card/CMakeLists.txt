add_library(sdCard INTERFACE)

target_sources(sdCard INTERFACE
)

target_include_directories(sdCard INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/lib/
)

target_link_libraries(sdCard INTERFACE pico_stdlib FatFs_SPI)
