cmake_minimum_required(VERSION 3.10)

# Project name
project(Library_Management_System)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR})

# Specify the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Collect all source files
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/data_structures/*.cpp
)

# Add the executable
add_executable(library_system ${SOURCES})