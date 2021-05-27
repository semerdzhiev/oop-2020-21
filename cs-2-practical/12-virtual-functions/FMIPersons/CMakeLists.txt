cmake_minimum_required(VERSION 3.19)
project(FMIPersons)

set(CMAKE_CXX_STANDARD 20)

add_executable(FMIPersons main.cpp Person.cpp Person.h Student.cpp Student.h Lecturer.cpp Lecturer.h FacultyMember.cpp FacultyMember.h)