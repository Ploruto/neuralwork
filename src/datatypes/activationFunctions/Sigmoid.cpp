#include <neuralwork/datatypes/activationFunctions/Sigmoid.hpp>
#include <neuralwork/datatypes/vector.hpp>

using namespace neuralwork::activationFunctions;
using namespace neuralwork::vector;

float getValue(float value) {
    return 1.0f / (1.0f + exp(-value));
}

float getDerivativeValue(float value) {
    return getValue(value) * (1.0f - getValue(value));
}

float getReversedValue(float value) {
    return log(value / (1.0f - value));
}

vector<float> getValue(vector<float> values) {
    vector<float> result(values.size());
    for (int i = 0; i < values.size(); i++) {
        result[i] = getValue(values[i]);
    }
    return result;
}

vector<float> getDerivativeValue(vector<float> values) {
    vector<float> result(values.size());
    for (int i = 0; i < values.size(); i++) {
        result[i] = getDerivativeValue(values[i]);
    }
    return result;
}

vector<float> getReversedValue(vector<float> values) {
    vector<float> result(values.size());
    for (int i = 0; i < values.size(); i++) {
        result[i] = getReversedValue(values[i]);
    }
    return result;
}