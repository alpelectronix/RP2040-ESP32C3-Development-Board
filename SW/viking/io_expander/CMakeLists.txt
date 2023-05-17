add_library(SLG46826 INTERFACE)

target_sources(SLG46826 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/core/SLG46826.c
    ${CMAKE_CURRENT_LIST_DIR}/core/HAL_SLG46826.c
)

target_include_directories(SLG46826 INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/core/
)

target_link_libraries(SLG46826 INTERFACE pico_stdlib hardware_i2c)