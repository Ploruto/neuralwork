#include <gtest/gtest.h>
#include <neuralwork/datatypes/matrix.hpp>
#include <neuralwork/datatypes/vector.hpp>

TEST(matrixTest, emptyMatrixConstructorTest)
{
    neuralwork::matrix<int> m1;
    EXPECT_EQ(m1[0][0], 0);
}

TEST(matrixTest, matrixConstructorWithVectorTest)
{
    neuralwork::matrix<int> m2(std::vector<neuralwork::vector<int>>({
        neuralwork::vector<int>({1, 2, 3}),
        neuralwork::vector<int>({4, 5, 6}),
        neuralwork::vector<int>({7, 8, 9})
    }));

    EXPECT_EQ(m2[0][0], 1);
    EXPECT_EQ(m2[0][1], 2);
    EXPECT_EQ(m2[0][2], 3);
    EXPECT_EQ(m2[1][0], 4);
    EXPECT_EQ(m2[1][1], 5);
    EXPECT_EQ(m2[1][2], 6);
}

TEST(matrixTest, matrixConstructorWithArrayTest)
{
    neuralwork::matrix<int> m3(new int[6] {1, 2, 3, 4, 5, 6}, 2, 3);
    EXPECT_EQ(m3[0][0], 1);
    EXPECT_EQ(m3[0][1], 2);
    EXPECT_EQ(m3[0][2], 3);
    EXPECT_EQ(m3[1][0], 4);
    EXPECT_EQ(m3[1][1], 5);
    EXPECT_EQ(m3[1][2], 6);
}