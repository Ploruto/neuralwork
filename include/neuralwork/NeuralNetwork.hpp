#ifndef NEURALWORK_NEURALNETWORK
#define NEURALWORK_NEURALNETWORK
#include <neuralwork/datatypes/matrix.hpp>
#include <neuralwork/datatypes/neuralLayer.hpp>
#include <neuralwork/datatypes/vector.hpp>

namespace neuralwork {

template <typename T>
struct neuralNetwork
{
private:
    vector<neuralLayer<T>> _layers;
    int _noLayers;

public:
    neuralNetwork(vector<int> numberOfNodesInEveryLayer)
    {
        this->_noLayers = numberOfNodesInEveryLayer.getSize();
        this->_layers = vector<neuralLayer<T>>(neuralLayer<T>(numberOfNodesInEveryLayer[0], 0));
        for (int i = 1; i < numberOfNodesInEveryLayer.getSize() - 1; i++)
        {
            this->_layers.push_back(neuralLayer<T>(numberOfNodesInEveryLayer[i], numberOfNodesInEveryLayer[i - 1]));
        }
    }

    // backpropagation
    void optimize(vector<T> &inputData, vector<T> &Y) {
        this->_layers[0].calculateDerivativeOfZValues(y, true);
        this->_layers[0].adjustWeights();
        this-
        for (int i = _noLayers - 1; i >= 0; i--) {
            this->_layers[i].calculateDerivativeOfZValues();
        }
    }
};

}
#endif