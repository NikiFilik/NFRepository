cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME lab4)
project("${PROJECT_NAME}" LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories("inc")
add_executable("${PROJECT_NAME}" src/main.cpp inc/Game.hpp src/Game.cpp inc/Circle.hpp src/Circle.cpp inc/functions.hpp src/functions.cpp)
target_link_libraries("${PROJECT_NAME}" PRIVATE sfml-graphics)
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_17)

install(TARGETS "${PROJECT_NAME}")