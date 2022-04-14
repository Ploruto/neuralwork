#include <gtest/gtest.h>
#include <neuralwork/datatypes/vector.hpp>


TEST(vectorTest, vector_test)
{
    neuralwork::vector<int> v1;
    EXPECT_EQ(v1[0], 0);

    neuralwork::vector<int> v2(std::vector<int>({1, 2, 3}));
    EXPECT_EQ(v2[0], 1);
    EXPECT_EQ(v2[1], 2);

    neuralwork::vector<int> v3(new int[3] {1, 2, 3}, 3);
    EXPECT_EQ(v3[0], 1);


}

