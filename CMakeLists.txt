cmake_minimum_required(VERSION 3.7.0)
project(integral_switch)

set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c++11 -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/test)

enable_testing()
