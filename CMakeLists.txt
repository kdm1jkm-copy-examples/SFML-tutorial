cmake_minimum_required(VERSION 3.10)
project(SFML-tutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        headers/GameState.h
        src/Game.cpp headers/Game.h)

include_directories(${PROJECT_SOURCE_DIR}/headers)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFML-tutorial ${SOURCE_FILES})
target_link_libraries(SFML-tutorial sfml-graphics sfml-audio)