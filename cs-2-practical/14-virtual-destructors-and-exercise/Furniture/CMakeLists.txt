cmake_minimum_required(VERSION 3.19)
project(Furniture)

set(CMAKE_CXX_STANDARD 20)

include_directories(Headers)

add_executable(Furniture main.cpp Sources/Furniture.cpp Headers/Furniture.h Sources/Table.cpp Headers/Table.h Sources/Chair.cpp Headers/Chair.h Sources/Bed.cpp Headers/Bed.h Headers/MyVector.h)