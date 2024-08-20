# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(StochasticVolatility)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executables for each main.cpp file
add_executable(MainExecutable main.cpp correlated_snd.cpp heston_mc.cpp option.cpp payoff.cpp statistics.cpp)

add_executable(CSNDExecutable csnd_main.cpp correlated_snd.cpp statistics.cpp)

# Include directories (for header files)
target_include_directories(MainExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(CSNDExecutable PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries (if needed)
# No additional libraries needed as it only uses standard C++ libraries
