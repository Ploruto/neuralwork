#include <gtest/gtest.h>
#include <iostream>
#include <neuralwork/datatypes/activationFunctions/ActivationFunction.hpp>
#include <neuralwork/datatypes/activationFunctions/Sigmoid.hpp>

float test(const neuralwork::activationFunctions::ActivationFunction &activationFunction, float value){
    return activationFunction.getValue(value);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}

