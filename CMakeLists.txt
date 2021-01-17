cmake_minimum_required(VERSION 3.10)
project(SFML-tutorial)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SFMLTest main.cpp)
target_link_libraries(SFMLTest sfml-graphics sfml-audio)