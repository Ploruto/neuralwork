#ifndef NEURALWORK_NEURON
#define NEURALWORK_NEURON

namespace neuralwork {
template<typename T>
struct neuron
{
private:
    T _value;
    float _bias;
public:
    // default constructor
    neuron() {
        this->_value = 0;
        this->_bias = 0;
    }
    // constructor with value
    neuron(T value) {
        this->_value = value;
        this->_bias = 0;
    }
    // constructor with value and bias
    neuron(T value, float bias) {
        this->_value = value;
        this->_bias = bias;
    }
    // getter
    T get() {
        return this->_value;
    }
    // setter
    void set(T value) {
        this->_value = value;
    }
    // getter
    float getBias() {
        return this->_bias;
    }
    // setter
    void setBias(float bias) {
        this->_bias = bias;
    }
};


};

}

#endif