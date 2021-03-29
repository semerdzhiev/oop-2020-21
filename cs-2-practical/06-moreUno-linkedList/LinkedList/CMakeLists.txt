cmake_minimum_required(VERSION 3.17)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp Node.h List.h ListIterator.h Node.cpp ListIterator.cpp List.cpp)