cmake_minimum_required(VERSION 3.4...3.21)
project(venues LANGUAGES CXX)

SET(CMAKE_BUILD_TYPE "Release")

find_package(pybind11 REQUIRED)
find_package(GSL REQUIRED)

pybind11_add_module(venues main.cpp)
