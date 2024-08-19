# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(VanillaOption)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(VanillaOptionExecutable main.cpp vanilla_option.cpp)

# Include directories (if needed)
# target_include_directories(Chapter3Executable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# If you need to link against any libraries, add them here
# target_link_libraries(Chapter3Executable <library_name>)

# Optionally add flags for compiler optimizations, warnings, etc.
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# If you have a custom makefile you'd like to use, you can add the following:
# set(MAKEFILE ${CMAKE_CURRENT_SOURCE_DIR}/makefile)
