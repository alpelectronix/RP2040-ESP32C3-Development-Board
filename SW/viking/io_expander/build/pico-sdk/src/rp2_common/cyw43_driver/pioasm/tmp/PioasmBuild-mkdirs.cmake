# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Caner/Documents/Pico/pico-sdk/tools/pioasm"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pioasm"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/tmp"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src"
  "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/RP2040-ESP32C3 Development Board/RP2040-ESP32C3_Dev_Board/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
