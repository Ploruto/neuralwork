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
    std::vector<neuralLayer<T>> _layers;
    int _noLayers;
    matrix<matrix<T>> _matrixOfLayersAndDerivativesOfWeights(); // derivativeMatrix = x[layer][trainingIndex]
    matrix<vector<T>> _matrixOfLayersAndDerivativesOfBiases();
    float _learningRate;

public:
    neuralNetwork(vector<int> numberOfNodesInEveryLayer, float _learningRate = 0.01) {
        // initializing variables
        return;
        // this->_noLayers = numberOfNodesInEveryLayer.getSize();
        // neuralLayer<T> firstLayer(numberOfNodesInEveryLayer[0], 0);
        // this->_layers.push_back(firstLayer);
        // matrix<matrix<T>> initWeights(this->_noLayers, 0);
        // this->_matrixOfLayersAndDerivativesOfWeights = initWeights;
        // matrix<vector<T>> initBiases(this->_noLayers, 0);
        // this->_matrixOfLayersAndDerivativesOfBiases = initBiases;
        // creating each layer (except the input layer that already got created)
        for (int i = 1; i < numberOfNodesInEveryLayer.getSize() - 1; i++)
        {
            neuralLayer<T> newLayer(numberOfNodesInEveryLayer[i], numberOfNodesInEveryLayer[i - 1]);
            this->_layers.push_back(newLayer);
        }
    }

    void calculateNodeValues(vector<T> &inputData, vector<T> &Y) {
        // itereate through the layers
        for (int i = 1; i < this->_noLayers; i++) {
            this->_layers[i].calculateNodes(this->_layers[i-1].getNodes());
        }
    }

    void trainOnData(vector<T> &inputData, vector<T> &Y) {
        // calculating node values
        this->calculateNodeValues();
        // training column vector
        vector<matrix<T>> trainingWeightColumn(this->_layers[this->_noLayers-1].getSize());
        vector<vector<T>> trainingBiasColumn(this->_layers[this->_noLayers-1].getSize());
        // treating the last layer specially
        this->_layers[this->_noLayers-1].calculateDerivativeOfZValues(Y, true);
        trainingWeightColumn.setAt(0, this->_layers[this->_noLayers-1].calculateDerivativeOfWeights(this->_layers[this->_noLayers-2].getNodes()));
        trainingBiasColumn.setAt(0, this->_layers[this->_noLayers-1].calculateDerivativeOfBiases);
        // backpropagate through remaining layers
        for (int i = this->_noLayers - 2; i >= 0; i--) {
            if (i > 0) {
                this->_layers[i].calculateDerivativeOfZValues();
                trainingWeightColumn.setAt(i, this->_layers[i].calculateDerivativeOfWeights(this->_layers[i-1].getNodes()));
            }
            trainingBiasColumn.setAt(i, this->_layers[i].calculateDerivativeOfBiases);
        }
        this->_matrixOfLayersAndDerivativesOfWeights.push_back_column(trainingWeightColumn);
        this->_matrixOfLayersAndDerivativesOfBiases.push_back_column(trainingBiasColumn);
    }

    void optimizeSelf() {
        int noExamples = this->_matrixOfLayersAndDerivativesOfBiases[0].getSize();
        vector<int> oneVector(noExamples, 1); // vector containing only 1s
        vector<matrix<T>> addedWeightDerivativesOfLayer = this->_matrixOfLayersAndDerivativesOfWeights * oneVector;
        vector<vector<T>> addedBiasDerivativesOfLayer = this->_matrixOfLayersAndDerivativesOfBiases * oneVector;
        // interate through each layer; calculate sum of derivatives by iterating through training data; adjust accordingly
        for (int i = 0; i < this->_noLayers;  i++) {
            matrix<T> adjustedWeights = this->_layers[i].getWeights() + addedWeightDerivativesOfLayer[i] * (-this->_learningRate/noExamples);
            vector<T> adjustedBiases = this->_layers[i].getBiases() + addedBiasDerivativesOfLayer[i] * (-this->_learningRate/noExamples);
            this->_layers[i].setWeights(adjustedWeights);
            this->_layers[i].setBiases(adjustedBiases);
        }
    }
};

}
#endif