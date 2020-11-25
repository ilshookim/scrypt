# Scrypt is a string crypto for AES-CRC-Padding designed by ilshookim
# MIT License
#
# https://github.com/ilshookim/scrypt

cmake_minimum_required(VERSION 3.0.0)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")
    message(" [INFO] VCPKG CMAKE_TOOLCHAIN_FILE = ${CMAKE_TOOLCHAIN_FILE}")
endif()

project(scrypt VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(fmt CONFIG REQUIRED)
find_package(cryptopp CONFIG REQUIRED)

set(CONFIG_SRC config.h.in config.h)
configure_file(${CONFIG_SRC})
include_directories(${PROJECT_BINARY_BIN})

include_directories(./)

set(MAIN_SRC main.cpp)
add_executable(scrypt ${MAIN_SRC})

target_link_libraries(scrypt PRIVATE fmt::fmt)
target_link_libraries(scrypt PRIVATE cryptopp-static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
