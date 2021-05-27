cmake_minimum_required(VERSION 3.19)
project(TemplatesAndAbstractClasses)

set(CMAKE_CXX_STANDARD 20)

include_directories(Interfaces)

add_executable(TemplatesAndAbstractClasses main.cpp Interfaces/Printable.h Interfaces/ToFile.h Interfaces/Point.h Point1D.cpp Point1D.h MyVector.h)