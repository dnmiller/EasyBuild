#include "gtest/gtest.h"
#include "MyMath.hpp"


// Test that our function returns the square of a number. This is just meant
// to shown how to incorporate gtest into the build. See the Google Test
// documentation for instructions on writing tests.
TEST(MyMath, mySquare)
{
    EXPECT_EQ(9, mySquare(3));
}

