cmake_minimum_required(VERSION 3.13)
project("Unit Test Example")

add_library(SortLib STATIC src/Library.cpp src/Library.h)

add_executable(SimpleApp src/SimpleApp.cpp)
target_link_libraries(SimpleApp SortLib)

add_executable(SortTest test/SortTest.cpp)
target_link_libraries(SortTest SortLib)
