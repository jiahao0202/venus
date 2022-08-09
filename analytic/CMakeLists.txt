cmake_minimum_required(VERSION 3.4...3.21)
project(venus LANGUAGES CXX)

file(GLOB_RECURSE PRICER_FILES "./*.cpp")
add_library(analytic_pricer STATIC ${PRICER_FILES})