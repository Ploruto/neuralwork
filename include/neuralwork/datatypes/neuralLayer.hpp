#ifndef NEURALWORK_LAYER
#define NEURALWORK_LAYER

#include <neuralwork/datatypes/matrix.hpp>
#include <neuralwork/datatypes/sigmoid.hpp>

namespace neuralwork {
template<typename T>
struct neuralLayer {

private:
    vector<T> _nodes;
    vector<T> _bias;
    matrix<T> _weights; // weights[i][j] is the weight from node j to node i in the next layer; weights are associated with nodes to the right
    vector<T> _derivativeofZValues;
    vector<T> _derivativeofBias;
    matrix<T> _derivativeofWeights;

public:
    // defining the constructor
    neuralLayer(int size, int sizeOfPreviousLayer) {
        return;
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

    vector<T> getBiases() const {
        return this->_bias;
    }

    matrix<T> getWeights() const {
        return this->_weights;
    }

    vector<T> getderivativeofZValues() const {
        return this->_derivativeofZValues;
    }

    int getSize() {
        return this->_nodes.getSize();
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
    void calculateNodes(vector<T> &previousNodes) {
        this->_nodes = sigmoidOfVector(this->_weights * previousNodes + this->_bias);
    }

    void calculateDerivativeOfZValues(vector<T> &input = nullptr, bool isLastLayer = false) {
        // this function already handles the influence of sigmoid
        // this function must be called before adjusting weights and biases
        vector<T> ZValuesThisLayer = sigmoidReversedVector(this->_nodes);
        if (isLastLayer) { // when this is the last layer the derivatives of the nodes are simply: 2 * (y - node); since we actually want the derivative of Z, we multiply further with 'sigmoid(node)
            for (int i = 0; i < this->_derivativeofZValues.getSize(); i++) {
                this->_derivativeofZValues.setAt(i, 2 * (input[i] - this->_nodes[i]) * sigmoidDerivative(ZValuesThisLayer[i]));
            }
        } else { // otherwise each node influence every other node in the next layer by the according weight; sum all these influences up; next, apply the derivative of sigmoid
            for (int i = 0; i < this->_derivativeofZValues.getSize(); i++) { // i iterates through the active layer
                T sum = 0;
                for (int j = 0; j < this->_weights.getSize(); j++) { // j iterates through the next layer
                    sum += this->_weights[j][i];
                }
                this->_derivativeofZValues.setAt(i, sum * sigmoidDerivative(ZValuesThisLayer[i]));
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
                this->_derivativeofWeights.setAt(i, j, this->_derivativeofZValues[i]);
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