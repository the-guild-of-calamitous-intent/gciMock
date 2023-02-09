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