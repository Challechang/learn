cmake_minimum_required(VERSION 3.5)
project(learn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB all_dirs "${PROJECT_SOURCE_DIR}/*.cpp")

foreach(dir ${all_dirs})
    message(${dir})
    if (NOT IS_DIRECTORY ${dir})
        get_filename_component(filename ${dir} NAME_WE)
        add_executable(${filename} ${dir})
    endif ()

endforeach()