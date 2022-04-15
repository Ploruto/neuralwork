#include <gtest/gtest.h>
#include <neuralwork/datatypes/vector.hpp>

using namespace neuralwork;

TEST(vectorTest, equalSizeCheck) {
    vector<int> v1(2);
    vector<int> v2(2);

    EXPECT_EQ(v1[0], 0);
}