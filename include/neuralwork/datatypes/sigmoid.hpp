#ifndef NEURALWORK_SIGMOID
#define NEURALWORK_SIGMOID

#include <math.h>
#include <neuralwork/datatypes/vector.hpp>


// definining sigmoid function
template<typename T>
T sigmoid(const T &x) {
    return 1 / (1 + std::exp(-x));
}

template<typename T>
neuralwork::vector<T> sigmoidOfVector(neuralwork::vector<T> &v) {
    neuralwork::vector<T> result = v; // result is a copy of v
    for (int i = 0; i < v.getSize(); i++) {
        result.setAt(i, sigmoid(v[i]));
    }
    return result;
}

template<typename T>
T sigmoidDerivative(const T &x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

template<typename T>
T sigmoidReversed(const T &x) {
    return std::log(x / (1 - x));
}

template<typename T>
neuralwork::vector<T> sigmoidReversedVector(neuralwork::vector<T> &v) {
    neuralwork::vector<T> result = v; // result is a copy of v
    for (int i = 0; i < v.getSize(); i++) {
        result.setAt(i, reverseSigmoid(v[i]));
    }
    return result;
}

#endif