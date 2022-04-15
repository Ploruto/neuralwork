#ifndef NEURALWORK_NEURALLAYER
#define NEURALWORK_NEURALLAYER

#include <neuralwork/datatypes/matrix.hpp>


namespace neuralwork {
template<typename T>
struct neuralLayer {

private:
    vector<T> _activationValues;
    vector<T> _biases;
    matrix<T> _weights; // weights[i][j] is the weight from node j to node i in the next layer; weights are associated with nodes to the right
    vector<T> _derivativeOfZValues;
    vector<T> _derivativeOfBiases;
    vector<T> _derivativeOfWeights;

public:
    // defining the constructor
    neuralLayer(const int &size, const int &sizeOfPreviousLayer) {

    }
    void randomize() {
        this->_activationValues.randomize();
        this->_biases.randomize();
        this->_weights.randomize();
        this->_derivativeOfZValues.randomize();
    }

    void calculateDerivativeofZValues(vector<T> &derivativeofZValues) {
        this->_derivativeOfZValues = derivativeofZValues;
    }

    // defining other methods
    void calculateNodes(vector<T> &input) {
        this->_activationValues = sigmoidOfVector(this->_weights * input + this->_biases);
    }

    void calculateDerivativeOfZValues(vector<T> &input = nullptr, bool isLastLayer = false) {
        // this function already handles the influence of sigmoid
        // this function must be called before adjusting weights and biases
        const vector<T> ZValuesThisLayer = sigmoidReversedVector(this->_activationValues);
        if (isLastLayer) { // when this is the last layer the derivatives of the nodes are simply: 2 * (y - node); since we actually want the derivative of Z, we multiply further with 'sigmoid(node)
            for (int i = 0; i < this->_derivativeOfZValues.getSize(); i++) {
                this->_derivativeOfZValues.setAt(i, 2 * (input[i] - this->_activationValues[i]) * sigmoidDerivative(Z[i]));
            }
        } else { // otherwise each node influence every other node in the next layer by the according weight; sum all these influences up; next, apply the derivative of sigmoid
            for (int i = 0; i < this->_derivativeOfZValues.getSize(); i++) { // i iterates through the active layer
                T sum = 0;
                for (int j = 0; j < this->_weights.getSize(); j++) { // j iterates through the next layer
                    sum += this->_weights[j][i];
                }
                this->_derivativeOfZValues.setAt(i, sum * sigmoidDerivative(Z[i]));
            }
        }
    }

    vector<T> calculateDerivativeOfWeights(vector<T> &previousNodes) {
        for (int i = 0; i < this->_weights.getSize(); i++) {
            for (int j = 0; j < this->_weights[i].getSize(); j++) {
                this->_derivativeOfWeights.setAt(i, j, this->_derivativeOfZValues[i] * previousNodes[j]);
            }
        }
        return this->_derivativeOfWeights;
    }

    vector<T> calculateDerivativeOfBiases() {
        for (int i = 0; i < this->_weights.getSize(); i++) {
            for (int j = 0; j < this->_weights[i].getSize(); j++) {
                this->_derivativeOfWeights.setAt(i, j, this->_derivativeOfZValues[i]);
            }
        }
        return this->_derivativeOfWeights;
    }

    void print() {
        std::cout<<"nodes: "<<std::endl;
        this->_activationValues.print();
        std::cout<<"bias: "<<std::endl;
        this->_biases.print();
        std::cout<<"weights: "<<std::endl;
        this->_weights.print();
        std::cout<<"derivativeofZValues: "<<std::endl;
        this->_derivativeOfZValues.print();
    }
};
}

#endif