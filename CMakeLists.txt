# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.18)

# Project's name

project(SettingsManager-Application)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# The following folder will be included
add_subdirectory(src)






