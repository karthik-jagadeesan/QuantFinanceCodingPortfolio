# Set the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(IR2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable for IR2
add_executable(IR2_main
    IR2_main.cpp
    IR2_source.cpp
    random.cpp
)

# Include directories for header files
target_include_directories(IR2_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link necessary libraries if any (optional)
