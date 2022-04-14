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
    vector<vector<matrix<T>>> _arrayOfDerivativesOfWeightsOfLayer; // derivativeMatrix = x[layer][trainingIndex]
    vector<vector<vector<T>>> _arrayOfDerivativesOfBiasesOfLayer;
    float _learningRate;

public:
    neuralNetwork(vector<int> numberOfNodesInEveryLayer, float _learningRate = 0.01)
    {
        this->_noLayers = numberOfNodesInEveryLayer.getSize();
        this->_layers = vector<neuralLayer<T>>(neuralLayer<T>(numberOfNodesInEveryLayer[0], 0));
        this->_arrayOfDerivativesOfWeightsOfLayer = vector<matrix<T>>(this->_noLayers);
        this->_arrayOfDerivativesOfBiasesOfLayer = vector<vector<T>>(this->_noLayers);
        for (int i = 1; i < numberOfNodesInEveryLayer.getSize() - 1; i++)
        {
            this->_layers.push_back(neuralLayer<T>(numberOfNodesInEveryLayer[i], numberOfNodesInEveryLayer[i - 1]));
        }
    }

    void trainOnData(vector<T> &inputData, vector<T> &Y) {
        // initializing arrays
        for (int i = 0; i < this->_noLayers; i++) {
            this->_arrayOfDerivativesOfWeightsOfLayer[i] = vector<matrix<T>>();
        }
        // treating the last layer specially
        this->_layers[this->_noLayers-1].calculateDerivativeOfZValues(y, true);
        this->_arrayOfDerivativesOfWeights.push_back(this->_layers[this->_noLayers-1].calculateDerivativeOfWeights);
        this->_arrayOfDerivativesOfBiases.push_back(this->_layers[this->_noLayers-1].calculateDerivativeOfBiases);
        // backpropagate through remaining layers
        for (int i = this->_noLayers - 2; i >= 0; i--) {
            this->_layers[i].calculateDerivativeOfZValues();
            this->_arrayOfDerivativesOfWeights.push_back(this->_layers[i].calculateDerivativeOfWeights);
            this->_arrayOfDerivativesOfBiases.push_back(this->_layers[i].calculateDerivativeOfBiases);
        }
    }

    void optimizeSelf() {
        int noExamples = this->_arrayOfDerivativesOfBiases.getSize();
        matrix<T> addedWeightDerivativesOfLayer(this->_arrayOfDerivativesOfWeights.getRows(), this->_arrayOfDerivativesOfWeights.getRows());
        vector<T> addedBiasDerivativesOfLayer(this->_arrayOfDerivativesOfBiases.getSize());
        // interate through each layer; calculate sum of derivatives by iterating through training data; adjust accordingly
        for (int i = 0; i < this->_noLayers; i++) {
            addedWeightDerivativesOfLayer = this->_arrayOfDerivativesOfWeights[0];
            addedBiasDerivativesOfLayer = this->_arrayOfDerivativesOfBiases[0];
            for (int j = 1; j < noExamples; j++) {
                addedWeightDerivativesOfLayer += this->_arrayOfDerivativesOfWeights[0]
            }
        }
    }
};

}
#endif