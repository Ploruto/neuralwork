#include <gtest/gtest.h>
#include <neuralwork/NeuralNetwork.hpp>
//#include <neuralwork/datatypes/vector.hpp>
int main(int argc, char **argv) {
    int arr[] = {3, 3, 3};
    neuralwork::vector<int> v(arr, 3);
    neuralwork::neuralNetwork<float> AI(v);
    // std::vector<neuralwork::vector<int>> stdV({v, v, v});
    // neuralwork::matrix<int> m(stdV);
    // std::vector<neuralwork::matrix<int>> matricies({m, m, m});
    // std::vector<neuralwork::vector<neuralwork::matrix<int>>> VMatricies({matricies, matricies, matricies});
    // ::testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}