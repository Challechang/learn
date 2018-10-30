cmake_minimum_required(VERSION 3.5)
project(learn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_executable(template template.h template.cpp)

add_executable(operator_overload operator_overload.cpp)

add_executable(static_init static_init.cpp)