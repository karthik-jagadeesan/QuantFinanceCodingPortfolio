# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(VanillaOption)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(VanillaOption main.cpp vanilla_option.cpp)

# Include directories (if needed)
# If you had header files in different directories, you would add them here.
# target_include_directories(VanillaOption PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries (if needed)
# In this case, since cmath is a standard library, no need to link additional libraries.
# target_link_libraries(VanillaOption)

# Optionally add flags for compiler optimizations, warnings, etc.
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
