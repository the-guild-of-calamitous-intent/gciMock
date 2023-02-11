
add_executable(pty pty.cpp)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        # ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(pty
    PUBLIC
        #
        gciMock
)
