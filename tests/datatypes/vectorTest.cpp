#include <gtest/gtest.h>
#include <neuralwork/datatypes/vector.hpp>

using namespace neuralwork;

TEST(vectorTest, equalSizeCheck) {
    vector<int> v1(2);
    vector<int> v2(2);

    EXPECT_EQ(v1[0], 0);
}

TEST(vectorTest, randomize) {
    vector<float> v1(2);
    v1.randomize();
    v1.print();
    
}