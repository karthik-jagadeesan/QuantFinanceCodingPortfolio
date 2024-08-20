# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(IR1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for IR1
add_executable(IR1_main
    IR1_main.cpp
    IR1_source.cpp
    random.cpp
)

# Include directories for header files
target_include_directories(IR1_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link necessary libraries if any (optional)
