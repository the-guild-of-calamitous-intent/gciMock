# v3.14 required for FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)

PROJECT(gcimock
    VERSION "2023.02.11"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

cmake_host_system_information(RESULT HOST QUERY HOSTNAME)
cmake_host_system_information(RESULT OSN QUERY OS_NAME)
cmake_host_system_information(RESULT OS_VERSION QUERY OS_RELEASE)
cmake_host_system_information(RESULT PROC QUERY PROCESSOR_DESCRIPTION)

message(STATUS "-------------------------------------")
message(STATUS "  Project: ${PROJECT_NAME}")
message(STATUS "  Version: ${CMAKE_PROJECT_VERSION}")
message(STATUS "  C++ ${CMAKE_CXX_STANDARD}")
message(STATUS "-------------------------------------")
message(STATUS " ${HOST}")
message(STATUS " ${OSN}: ${OS_VERSION}")
message(STATUS " ${PROC}")
message(STATUS "-------------------------------------")

# Add the library target
add_library(${PROJECT_NAME}
    src/mock_serial.cpp
    src/Arduino.cpp
    src/Wire.cpp
    src/Servo.cpp
    src/SPI.cpp
)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


# Examples ====================================================================
option(BUILD_EXAMPLES "Examples" OFF)
message(STATUS "Building gciMock examples is ${BUILD_EXAMPLES}")
if (BUILD_EXAMPLES)
    add_subdirectory(examples/pty)
endif()

option(BUILD_GTESTS "build gtests" ON)
message(STATUS "Building gciMock gtests is ${BUILD_GTESTS}")
if (BUILD_GTESTS)
    # add_subdirectory(gtests)
endif()

