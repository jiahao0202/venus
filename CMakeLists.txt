cmake_minimum_required(VERSION 3.4...3.21)
project(venus LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_BUILD_TYPE "Debug")

enable_testing()

add_subdirectory("unittests")
add_subdirectory("analytic")

# find_package(pybind11 REQUIRED)

# file(GLOB DIR_SRCS analytic/*.cpp)

# pybind11_add_module(venus main.cpp ${DIR_SRCS})
