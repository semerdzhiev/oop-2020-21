cmake_minimum_required(VERSION 3.17)
project(CarDealership)

set(CMAKE_CXX_STANDARD 20)

add_executable(CarDealership main.cpp Car.cpp Car.h EngineDetails.cpp EngineDetails.h Dealership.cpp Dealership.h ManufactureDetails.cpp ManufactureDetails.h VisualDetails.cpp VisualDetails.h)