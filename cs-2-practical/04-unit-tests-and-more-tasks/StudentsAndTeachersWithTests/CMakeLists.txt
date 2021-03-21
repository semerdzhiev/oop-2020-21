cmake_minimum_required(VERSION 3.17)
project(StudentsAndTeachers)

set(CMAKE_CXX_STANDARD 20)

add_executable(StudentsAndTeachers Student.cpp Student.h DynamicArray.cpp DynamicArray.h Course.cpp Course.h RetiredTeacher.cpp RetiredTeacher.h test.cpp catch2/catch.cpp catch2/catch.h)