cmake_minimum_required(VERSION 3.10)
project(AngularMomentumDemo)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(include)

add_executable(demo
    src/main.cpp
    src/physics.cpp
    src/graphics.cpp
)

target_link_libraries(demo ${OpenCV_LIBS})