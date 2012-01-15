cmake_minimum_required(VERSION 2.8)
project(sudoku-solver)

# Force C89 compatibility.
add_definitions(-std=c89 -pedantic)
# Enable lots of warnings, keep the code clean!
add_definitions(-Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual)
# More warnings.
add_definitions(-Wstrict-prototypes -Wmissing-prototypes)
# Helps pickup code not supported by MCVC.
add_definitions(-Wdeclaration-after-statement)

# Set default built type to DEBUG.
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE DEBUG CACHE STRING "Build types: DEBUG, RELEASE" FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE)

# Use different compiler flags for different build types; -DCMAKE_BUILD_TYPE
SET(CMAKE_C_FLAGS_NONE "-O3")
SET(CMAKE_C_FLAGS_DEBUG "-DDEBUG=1")

# By default, include our includes!
include_directories(${PROJECT_SOURCE_DIR}/include)

# Sub-directories that have their own CMake file.
add_subdirectory(src)
#add_subdirectory(test)