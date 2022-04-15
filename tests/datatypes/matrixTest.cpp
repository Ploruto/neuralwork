
#include <gtest/gtest.h>
#include <neuralwork/datatypes/matrix.hpp>
#include <neuralwork/datatypes/vector.hpp>
using namespace neuralwork;

// test all public functions except the constructors
TEST(matrixTest, getValueTest) {
    matrix<int> m1(2, 2);
    matrix<int> m2(2, 2);

    EXPECT_EQ(m1(0, 0), 0);
}

TEST(matrixTest, setValueTest) {
    matrix<int> m1(2, 2);
    matrix<int> m2(2, 2);

    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(1, 0) = 3;
    m1(1, 1) = 4;

    EXPECT_EQ(m1(0, 0), 1);
    EXPECT_EQ(m1(0, 1), 2);
    EXPECT_EQ(m1(1, 0), 3);
    EXPECT_EQ(m1(1, 1), 4);
}
TEST(matrixTest, vectorMultiplicationTest) {

}