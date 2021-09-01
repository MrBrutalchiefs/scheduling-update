cmake_minimum_required(VERSION 3.20)
project(scheduling)

set(CMAKE_CXX_STANDARD 11)

include(BoostMacros.cmake)
REQUIRE_BOOST_HEADERS()

# Header File
include_directories(${PROJECT_SOURCE_DIR}/robin-map/include)
include_directories(${PROJECT_SOURCE_DIR}/tinyxml/include)
include_directories(${PROJECT_SOURCE_DIR}/edmonds/include)
include_directories(${PROJECT_SOURCE_DIR}/tools/include)
#include_directories(${PROJECT_SOURCE_DIR}/tabu/include)


# Library
add_subdirectory(${PROJECT_SOURCE_DIR}/robin-map)
add_subdirectory(${PROJECT_SOURCE_DIR}/tinyxml)
add_subdirectory(${PROJECT_SOURCE_DIR}/edmonds)
add_subdirectory(${PROJECT_SOURCE_DIR}/tools)
#include_directories(${PROJECT_SOURCE_DIR}/tabu)

add_executable(scheduling main.cpp)
