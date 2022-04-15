#include <gtest/gtest.h>
#include <iostream>
#include <neuralwork/datatypes/activationFunctions/ActivationFunction.hpp>
#include <neuralwork/datatypes/activationFunctions/Sigmoid.hpp>

template<typename T>
struct test
{
    float get(float value){ return T::getValue(value); }
};


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    test<neuralwork::activationFunctions::Sigmoid> test;

    std::cout << test.get(15.0f) << std::endl;

    return 0;
}

