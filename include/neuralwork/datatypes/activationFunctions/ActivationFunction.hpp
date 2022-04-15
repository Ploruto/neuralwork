#ifndef NEURALWORK_ACTIVATIONFUNCTION
#define NEURALWORK_ACTIVATIONFUNCTION

#include <neuralwork/datatypes/vector.hpp>

namespace neuralwork{
    namespace activationFunctions{
        class ActivationFunction{
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