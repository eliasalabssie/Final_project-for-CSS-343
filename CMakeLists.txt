cmake_minimum_required(VERSION 3.10)
project(assignment4)

set(CMAKE_CXX_STANDARD 11)

add_executable(assignment4
        driver.cpp
        Blockbuster.cpp
        Blockbuster.h
        Classic.cpp
        Classic.h
        command.cpp
        command.h
        Customer.cpp
        Customer.h
        Drama.cpp
        Drama.h
        Movie.cpp
        Movie.h
        MovieDriver.cpp)
