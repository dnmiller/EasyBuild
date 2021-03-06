EasyBuild
=========

Skeleton code for a project using cmake for building, gtest for testing, and gcov for coverage checking

This is meant to be a starting point for projects written in C/C++. It
provides a directory structure and CMakeLists.txt files that set up some
targets for testing with gtest and coverage checking with gcov. It took way too long to figure out how to integrate cmake,
gtest, and gcov together, so creating a skeleton project for future use
seemed like a good idea. 

This is only compatible with OS X right now. It is far from complete.

Coverage checking with Clang requires some target libraries that probably
aren't needed (or even exist) on Windows/Linux. Upgrading for other
platforms will likely require some modifications to test/CMakeLists.txt and
cmake/CodeCoverage.cmake.

----------------------------------------------------------------------------

To use:

1. Download Google Test and unzip its contents into the gtest directory.

2. Create a build directory in the project root called "build".

3. cd into the build directory and type 

$ cmake ..
$ make

to build the current project. 

4. Modify the files in the src, include, and test directories to start
coding your project.

5. Update the CMakeLists.txt in the root directory to change the project
name and sources.

6. Goto 2.

----------------------------------------------------------------------------

The default settings assume that the standard build is an executable and not
a library. 

Compiler flags for the standard and test builds can be modified in the
CMakeLists.txt files in the src and test directories. Commonly used flags
are already included.

The unit tests do not use ctest, as it seemed to be mostly redundant with
gtest. Instead, use the target

$make test

to run the tests generated by gtest.

In addition to the standard and test targets, this also contains a coverage
target that can be built using

$make coverage

This will open up a browser window with code coverage results.

The target 

$make install

will move the standard build binary into the root bin directory. It will not
move the test binary.
