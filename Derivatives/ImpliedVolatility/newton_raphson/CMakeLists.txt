# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(NewtonRaphson)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(NewtonRaphson main.cpp black_scholes.cpp)

# Include directories (for header files)
target_include_directories(NewtonRaphson PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries (if needed)
# No additional libraries needed as it only uses standard C++ libraries
