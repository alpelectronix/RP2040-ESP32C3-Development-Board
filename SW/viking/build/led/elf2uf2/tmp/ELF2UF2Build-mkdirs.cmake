# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/pico-sdk/tools/elf2uf2"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/elf2uf2"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/tmp"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/src/ELF2UF2Build-stamp"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/src"
  "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/hakan/VSCodeProjects/RP2040-ESP32C3-Development-Board/SW/viking/build/led/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()
