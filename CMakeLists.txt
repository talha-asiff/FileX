cmake_minimum_required(VERSION 3.14)
project(RaylibApp CXX)

set(CMAKE_CXX_STANDARD 17)

# Automatically download and integrate Raylib
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
FetchContent_MakeAvailable(raylib)

# Compile executable
add_executable(app FileX.cpp)
target_link_libraries(app PRIVATE raylib)