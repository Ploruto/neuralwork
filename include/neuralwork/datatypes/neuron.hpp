#ifndef NEURALWORK_NEURON
#define NEURALWORK_NEURON

namespace neuralwork {
template<typename T>
struct neuron
{
private:
    // weights to connect to the next layer
    vector<T> _weights;
    // bias
    T _bias;

    // default constructor
    neuron() {
        this->_weights = vector<T>(1, 0);
        this->_bias = 0;
    }
    // constructor with default value and size
    neuron(int size) {
        this->_weights = vector<T>(size, 0);
        this->_bias = 0;
    }
    // constructor with std::vector
    neuron(std::vector<T> _weights, T _bias) {
        this->_weights = _weights;
        this->_bias = _bias;
    }
    // constructor with array of T
    neuron(T* arr, int size, T _bias): _vector(arr, size) {
        this->_bias = _bias;
    }
    // getter
    std::vector<T> get_weights() {
        return this->_weights;
    }
    // getter
    T get_bias() {
        return this->_bias;
    }
    // setter
    void set_bias(T _bias) {
        this->_bias = _bias;
    }
    // setter
    void set_weights(std::vector<T> _weights) {
        this->_weights = _weights;
    }
    // overload [] operator
    T& operator[](int index) {
        return this->_weights[index];
    }

};

}

#endif