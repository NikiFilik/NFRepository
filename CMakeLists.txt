cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME lab1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" lab1_main.cpp lab1_functions.hpp lab1_functions.cpp)

file(COPY "LaunchTime.txt" DESTINATION "/")