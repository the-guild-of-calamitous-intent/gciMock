# gciMock

Trying to funnel a lot of my various linux or Arduino mock interfaces
into one project instead of constantly recreating the wheel.

## `cmake` Usage

```cmake
# gciMock -----------------
FetchContent_Declare(gciMock
  GIT_REPOSITORY "git@github.com:the-guild-of-calamitous-intent/gciMock.git"
  GIT_TAG "origin/main"
  SOURCE_DIR "${CMAKE_BINARY_DIR}/_deps/gciMock"
)
set(EXAMPLES OFF CACHE INTERNAL "Dont build examples")
FetchContent_MakeAvailable(gciMock)
if(gciMock_POPULATED)
    message(STATUS "=> Found gciMock")
else()
    message(STATUS "*** Didn't find gciMock")
endif()



if (UNIX OR APPLE OR linux)
    message(STATUS "Using mock i2c ${gcimock_BINARY_DIR}")
    target_link_directories(${PROJECT_NAME}
        PUBLIC
            ${gcimock_BINARY_DIR}
            # ${squaternion_BINARY_DIR}
    )
    target_include_directories(${PROJECT_NAME}
        PUBLIC
            ${gcimock_SOURCE_DIR}/src
            # ${squaternion_SOURCE_DIR}/src
    )
    # target_link_libraries(${PROJECT_NAME}
    #     PRIVATE
    #         gciMock
    #         squaternion
    # )
endif()
```

# Todo:

- [ ] How to add `serial_mock` to `Serial` or `Stream`
- [ ] How to add `serial_mock` to `Wire`
- [ ] Add `Servo`
- [ ] Handle time better with `millis` and others
- [ ] Make a version for CPM:
    ```cmake
    # CPM ==========================================================================
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
    set(CPM_VERSION v0.35.1)
    if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
        message(STATUS "Downloading CPM.cmake")
        file(DOWNLOAD
            https://github.com/cpm-cmake/CPM.cmake/releases/download/${CPM_VERSION}/CPM.cmake
            ${CPM_DOWNLOAD_LOCATION}
        )
    else()
        message(STATUS "CPM ${CPM_VERSION} ready")
    endif()
    include(${CPM_DOWNLOAD_LOCATION})

    CPMAddPackage(
        NAME gciMock
        VERSION 2022.08.20
        GITHUB_REPOSITORY the-guild-of-calamitous-intent/gciMock
        OPTIONS
            "EXAMPLES OFF"
    )
    ```

# MIT License

**Copyright (c) 2019 The Guild of Calamitous Intent**

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.