# pull in common dependencies
#target_link_libraries(SLG46826 stdio)
#target_link_libraries(HAL_SLG46826)
cmake_minimum_required(VERSION 3.13)


project(SLG46826)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/SLG46826.c
  ${CMAKE_CURRENT_LIST_DIR}/SLG46826.h
)

target_include_directories(SLG46826 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(SLG46826 INTERFACE pico_stdlib)



project(HAL_SLG46826)

add_library(${PROJECT_NAME} INTERFACE)

target_sources(${PROJECT_NAME} INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/HAL_SLG46826.c
  ${CMAKE_CURRENT_LIST_DIR}/HAL_SLG46826.h
)

target_include_directories(HAL_SLG46826 INTERFACE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(HAL_SLG46826 INTERFACE pico_stdlib hardware_i2c)