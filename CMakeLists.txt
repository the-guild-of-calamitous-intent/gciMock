# v3.14 required for FetchContent_MakeAvailable
cmake_minimum_required(VERSION 3.14)

PROJECT(cgiMock
    VERSION "2023.02.08"
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
    # src/Wire.h
)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#         wirelib
#         # ${squaternion_SOURCE_DIR}
#         # $<$<PLATFORM_ID:Linux>:wirelib>
# )
# add_dependencies(${PROJECT_NAME} squaternion)


# Examples ====================================================================
# option(EXAMPLES "Examples" ON)
# message(STATUS "Building examples is ${EXAMPLES}")
# if (EXAMPLES)
#     add_subdirectory(examples)
# endif()

