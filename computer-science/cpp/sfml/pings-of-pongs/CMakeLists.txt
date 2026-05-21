cmake_minimum_required(VERSION 3.16)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(pong
    main.cpp
    game.cpp
    ball.cpp
    paddle.cpp
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(pong sfml-graphics sfml-window sfml-system)

configure_file(
    ${CMAKE_SOURCE_DIR}/Ubuntu-B.ttf
    ${CMAKE_BINARY_DIR}/Ubuntu-B.ttf
    COPYONLY
)
