cmake_minimum_required(VERSION 3.19)
project(Facebook)

set(CMAKE_CXX_STANDARD 20)

add_executable(Facebook main.cpp PictureData.cpp PictureData.h Comment.h UserData.cpp UserData.h)