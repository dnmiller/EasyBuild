cmake_minimum_required(VERSION 2.8)

# The project name will be the name of the binary executable created. The
# test code will also be named ${PROJECT_NAME}_test.
set(PROJECT_NAME my_project)
project(${PROJECT_NAME})

# Project numbers that aren't currently used for anything.
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 1)

# File containing the main function of the standard build. This is listed
# separately so that it's not included in the test suite build (otherwise we
# might have two main functions. This should be empty if only a library is
# being generated.
set(MAIN_SOURCE
        Main.cpp
    )

# Source files for the standard build. These are defined here so that the
# test suite knows which source files to compile against. Compiler options
# for the standard build are in the CMakeLists.txt file in the src
# subdirectory.
set(PROJECT_SOURCES
        MyMath.cpp
    )

# Source files for the test suite. This should only include source files in
# the test subdirectory. Compiler options for the test build are located in
# the CMakeLists.txt file in the test subdirectory.
set(TEST_SOURCES 
        TestMyMath.cpp
    )

# Tell cmake where to find the files that tell it where to find files. The
# cmake subdirectory should contain .cmake files that define custom
# functions and Find*.cmake files that tell cmake where to look for
# libraries. This must be done before the find_package commands.
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Find external libraries used by the program.

# The Boost date_time library doesn't really do anything for the sample
# program. It's meant to demonstrate how to find external libraries.
find_package(Boost 1.5.0 COMPONENTS date_time REQUIRED)

# Find the header files for the external libraries.
include_directories(${Boost_INCLUDE_DIR})

# Local header files are placed in the include directory.
include_directories(include)

# The googletest code should be unzipped and placed in the gtest directory.
# No user-created files should be placed in the gtest directory.
add_subdirectory(gtest)
include_directories(gtest/include)

# The add_subdirectory commands should be last.

# Project source files should be placed in the src subdirectory.
add_subdirectory(src)

# Test source files should be placed in the test subdirectory.
add_subdirectory(test)




