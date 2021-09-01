cmake_minimum_required(VERSION 3.20)
project(scheduling)

set(CMAKE_CXX_STANDARD 11)

include(BoostMacros.cmake)
REQUIRE_BOOST_HEADERS()

# Header File
include_directories(${PROJECT_SOURCE_DIR}/edmonds)
include_directories(${})

add_executable(scheduling main.cpp)
