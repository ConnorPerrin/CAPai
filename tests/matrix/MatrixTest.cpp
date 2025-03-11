#include <gtest/gtest.h>
#include "Matrix.h"

// Test case for default constructor
TEST(MatrixTest, DefaultConstructor) {
    Matrix m;
    EXPECT_EQ(m.get_rows(), 0);
    EXPECT_EQ(m.get_cols(), 0);
}

// Test case for parameterized constructor
TEST(MatrixTest, ParameterizedConstructor) {
    Matrix m(3, 3);
    EXPECT_EQ(m.get_rows(), 3);
    EXPECT_EQ(m.get_cols(), 3);
}

// Test case for addition
TEST(MatrixTest, Addition) {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix result = m1 + m2;
    // Add your own checks here
}

// Test case for multiplication
TEST(MatrixTest, Multiplication) {
    Matrix m1(2, 2);
    Matrix m2(2, 2);
    Matrix result = m1 * m2;
    // Add your own checks here
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
