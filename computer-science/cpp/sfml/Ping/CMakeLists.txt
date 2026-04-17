cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(MyProject main.cpp)
target_link_libraries(MyProject SFML::Graphics SFML::Window SFML::System)