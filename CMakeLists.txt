cmake_minimum_required(VERSION 3.16)
project(algorithms_repertoire_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header-only library target
add_library(algo INTERFACE)
target_include_directories(algo INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enable tests
enable_testing()
add_subdirectory(tests)

# Benchmarks (we'll add later)
add_subdirectory(benchmarks OPTIONAL)
