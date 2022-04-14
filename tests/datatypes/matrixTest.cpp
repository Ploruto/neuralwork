#include <gtest/gtest.h>
#include <neuralwork/datatypes/matrix.hpp>
#include <neuralwork/datatypes/vector.hpp>
using namespace neuralwork;

TEST(matrixTest, equalSizeCheck){
    matrix<int> m1(2, 2);
    matrix<int> m2(2, 2);

    EXPECT_EQ(m1[0][0], 0);
}