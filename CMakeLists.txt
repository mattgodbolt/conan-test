cmake_minimum_required(VERSION 3.12)
project(conan_test)

set(CMAKE_CXX_STANDARD 17)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
        BASIC_SETUP
        CONANFILE conanfile.txt
        CMAKE_TARGETS
        BUILD missing)

add_executable(conan_test main.cpp)
target_link_libraries(conan_test CONAN_PKG::fmt)
