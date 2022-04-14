#ifndef JOPHO_LAYER
#define JOPHO_LAYER

#include <neuralwork/datatypes/matrix.hpp>


// definining sigmoid function
namespace neuralwork {
template<typename T>
T sigmoid(const T &x) {
    return 1 / (1 + std::exp(-x));
}

template<typename T>
vector<T> sigmoidOfVector(vector<T> &v) {
    vector<T> result = v; // result is a copy of v
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
T sigmoidReversedVector(vector<T> &v) {
    vector<T> result = v; // result is a copy of v
    for (int i = 0; i < v.getSize(); i++) {
        result.setAt(i, reverseSigmoid(v[i]));
    }
    return result;
}


template<typename T>
struct neuralLayer {

private:
    vector<T> _nodes;
    vector<T> _bias;
    matrix<T> _weights; // weights[i][j] is the weight from node j to node i in the next layer; weights are associated with nodes to the right
    vector<T> _derivativeofZValues;
    vector<T> _derivativeofBias;
    vector<T> _derivativeofWeights;

public:
    // defining the constructor
    neuralLayer(const int &size, const int &sizeOfPreviousLayer) {
        this->_nodes = vector<T>(size);
        this->_bias = vector<T>(size);
        this->_weights = matrix<T>(size, sizeOfPreviousLayer);
        this->_derivativeofZValues = vector<T>(size);
        this->_derivativeofBias = vector<T>(size();
        this->_derivativeofWeights = matrix<T>(size, sizeOfPreviousLayer);
    }

    void randomize() {
        this->_nodes.randomize();
        this->_bias.randomize();
        this->_weights.randomize();
        this->_derivativeofZValues.randomize();
    }

    // defining the getter
    vector<T> getNodes() const {
        return this->_nodes;
    }

    vector<T> getBias() const {
        return this->_bias;
    }

    matrix<T> getWeights() const {
        return this->_weights;
    }

    vector<T> getderivativeofZValues() const {
        return this->_derivativeofZValues;
    }

    // defining the setter
    void setNodes(vector<T> &nodes) {
        this->_nodes = nodes;
    }

    void setBias(vector<T> &bias) {
        this->_bias = bias;
    }

    void setWeights(matrix<T> &weights) {
        this->_weights = weights;
    }

    void setderivativeofZValues(vector<T> &derivativeofZValues) {
        this->_derivativeofZValues = derivativeofZValues;
    }

    // defining other methods
    void calculateNodes(vector<T> &input) {
        this->_nodes = sigmoidOfVector(this->_weights * input + this->_bias);
    }

    void calculateDerivativeOfZValues(vector<T> &input = nullptr, bool isLastLayer = false) {
        // this function already handles the influence of sigmoid
        // this function must be called before adjusting weights and biases
        const vector<T> ZValuesThisLayer = sigmoidReversedVector(this->nodes);
        if (isLastLayer) { // when this is the last layer the derivatives of the nodes are simply: 2 * (y - node); since we actually want the derivative of Z, we multiply further with 'sigmoid(node)
            for (int i = 0; i < this->_derivativeofZValues.getSize(); i++) {
                this->_derivativeofZValues.setAt(i, 2 * (input[i] - this->_nodes[i]) * sigmoidDerivative(Z[i]));
            }
        } else { // otherwise each node influence every other node in the next layer by the according weight; sum all these influences up; next, apply the derivative of sigmoid
            for (int i = 0; i < this->_derivativeofZValues.getSize(); i++) { // i iterates through the active layer
                T sum = 0;
                for (int j = 0; j < this->_weights.getSize(); j++) { // j iterates through the next layer
                    sum += this->_weights[j][i];
                }
                this->_derivativeofZValues.setAt(i, sum * sigmoidDerivative(Z[i]));
            }
        }
    }

    vector<T> calculateDerivativeOfWeights(vector<T> &previousNodes) {
        for (int i = 0; i < this->_weights.getSize(); i++) {
            for (int j = 0; j < this->_weights[i].getSize(); j++) {
                this->_derivativeofWeights.setAt(i, j, this->_derivativeofZValues[i] * previousNodes[j]);
            }
        }
        return this->_derivativeofWeights;
    }

    vector<T> calculateDerivativeOfBiases() {
        for (int i = 0; i < this->_weights.getSize(); i++) {
            for (int j = 0; j < this->_weights[i].getSize(); j++) {
                this->_derivativeofWeights.setAt(i, j, alpha * this->_derivativeofZValues[i]);
            }
        }
        return this->_derivativeofWeights;
    }

    void print() {
        std::cout<<"nodes: "<<std::endl;
        this->_nodes.print();
        std::cout<<"bias: "<<std::endl;
        this->_bias.print();
        std::cout<<"weights: "<<std::endl;
        this->_weights.print();
        std::cout<<"derivativeofZValues: "<<std::endl;
        this->_derivativeofZValues.print();
    }
};
}

#endif