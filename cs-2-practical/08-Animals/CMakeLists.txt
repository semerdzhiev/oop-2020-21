cmake_minimum_required(VERSION 3.17)
project(Animals)

set(CMAKE_CXX_STANDARD 20)

include_directories("Headers"
        "Sources"
        "Catch2")

add_executable(animals "main.cpp"
        "Sources/AnimalFamily.cpp"
        "Sources/Fauna.cpp"
        "Sources/Planet.cpp"
        "Sources/Zoo.cpp")

add_executable(test "Tests/main.cpp"
        "Catch2/catch2.cpp"
        "Sources/AnimalFamily.cpp"
        "Sources/Fauna.cpp"
        "Sources/Planet.cpp"
        "Sources/Zoo.cpp")