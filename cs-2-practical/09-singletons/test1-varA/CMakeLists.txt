cmake_minimum_required(VERSION 3.19)
project(test1-varA)

set(CMAKE_CXX_STANDARD 20)

include_directories(Header
        Source)

add_executable(test1 main.cpp Source/Registration.cpp Header/Registration.h Source/Vehicle.cpp Header/Vehicle.h Source/VehicleList.cpp Header/VehicleList.h)