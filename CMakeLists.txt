
# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(toy-json-lib VERSION 1.0 LANGUAGES C)

# Add source files
add_library(leptjson STATIC src/leptjson.c)
target_include_directories(leptjson PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add test executable
add_executable(leptjson_test tests/test.c)
target_link_libraries(leptjson_test PRIVATE leptjson)
target_include_directories(leptjson_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Enable testing
include(CTest)
enable_testing()
add_test(NAME LeptjsonTest COMMAND leptjson_test)
