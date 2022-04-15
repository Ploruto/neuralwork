#ifndef NEURALWORK_ACTIVATIONFUNCTION_SIGMOID
#define NEURALWORK_ACTIVATIONFUNCTION_SIGMOID

namespace neuralwork{
    namespace activationFunctions{
        class Sigmoid : public ActivationFunction{
        public:
            static float getValue(float value);
            static float getDerivativeValue(float value);
            static float getReversedValue(float value);
            static vector<float> getValue(vector<float> values);
            static vector<float> getDerivativeValue(vector<float> values);
            static vector<float> getReversedValue(vector<float> values);
        };
    }
}

#endif