cmake_minimum_required(VERSION 3.24)
project(4_task)

set(CMAKE_CXX_STANDARD 20)

add_executable(4_task main.cpp cmake-build-debug/class_menu.cpp cmake-build-debug/class_menu.h figure.cpp figure.h)
