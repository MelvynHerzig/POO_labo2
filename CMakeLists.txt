cmake_minimum_required(VERSION 3.17)
project(labo2)

set(CMAKE_CXX_STANDARD 11)

add_executable(labo2 main.cpp ships/Ship.cpp ships/Ship.h Squadron.cpp Squadron.h ships/cargo/Cargo.cpp ships/cargo/Cargo.h ships/fighter/Fighter.cpp ships/fighter/Fighter.h ships/cargo/Shuttle.cpp ships/cargo/Shuttle.h ships/cargo/StarDestroyer.cpp ships/cargo/StarDestroyer.h ships/fighter/TIELN.cpp ships/fighter/TIELN.h ships/fighter/TIEIN.cpp ships/fighter/TIEIN.h)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wpedantic -Wsign-conversion")
