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
    std::vector<std::vector<double>> data1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> data2 = {{5, 6}, {7, 8}};

    Matrix m1(2, 2, data1);
    Matrix m2(2, 2, data2);
    Matrix result = m1 + m2;

    EXPECT_EQ(result(0, 0), 6);
    EXPECT_EQ(result(0, 1), 8);
    EXPECT_EQ(result(1, 0), 10);
    EXPECT_EQ(result(1, 1), 12);
}

// Test case for multiplication
TEST(MatrixTest, Multiplication) {
    std::vector<std::vector<double>> data1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> data2 = {{5, 6}, {7, 8}};

    Matrix m1(2, 2, data1);
    Matrix m2(2, 2, data2);
    Matrix result = m1 * m2;

    EXPECT_EQ(result(0, 0), 19);
    EXPECT_EQ(result(0, 1), 22);
    EXPECT_EQ(result(1, 0), 43);
    EXPECT_EQ(result(1, 1), 50);
}

// Test case for transpose
TEST(MatrixTest, Transpose) {
    std::vector<std::vector<double>> data = {{1, 2, 3}, {4, 5, 6}};
    Matrix m(2, 3, data);
    Matrix result = m.transpose();

    EXPECT_EQ(result.get_rows(), 3);
    EXPECT_EQ(result.get_cols(), 2);
    EXPECT_EQ(result(0, 0), 1);
    EXPECT_EQ(result(0, 1), 4);
    EXPECT_EQ(result(1, 0), 2);
    EXPECT_EQ(result(1, 1), 5);
    EXPECT_EQ(result(2, 0), 3);
    EXPECT_EQ(result(2, 1), 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
