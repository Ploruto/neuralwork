#ifndef NEURALWORK_MATRIX
#define NEURALWORK_MATRIX
#include <neuralwork/datatypes/vector.hpp>

namespace neuralwork {
template <typename T>
struct matrix {
private:
    vector<vector<T>> _matrix = vector<vector<T>>(0, vector<T>(0));

public:
    // default constructor
    matrix() {
        this->_matrix = vector<vector<T>>();
    }

    // constructor with size of matrix (rows, cols)
    matrix(int rows, int cols){
        this->_matrix = vector<vector<T>>(rows, vector<T>(cols, (T) 0.0f));
    }
        

    // constructor with size of matrix (rows, cols) and value
    matrix(int rows, int cols, T value) {
        this->_matrix = vector<vector<T>>(rows, vector<T>(cols, value));
    }

    // constructor with size of matrix (rows, cols) and values
    matrix(int rows, int cols, T *values) {
        this->_matrix = vector<vector<T>>(rows, vector<T>(cols, values));
    }


    vector<T> &operator[](int index) {
        return this->_matrix[index];
    }

    int getRows() {
        return this->_matrix.size();
    }

    int getCols() {
        return this->_matrix[0].size();
    }

    // scalar multiplication
    matrix<T> operator*(T scalar) {
        matrix<T> result(this->_matrix.size(), this->_matrix[0].size());
        for (int i = 0; i < this->_matrix.size(); i++) {
            for (int j = 0; j < this->_matrix[0].size(); j++) {
                result[i][j] = this->_matrix[i][j] * scalar;
            }
        }
        return result;
    }

    // vector multiplication
    vector<T> operator*(vector<T> inputVector) {
        vector<T> result(this->_matrix.size());
        for (int i = 0; i < this->_matrix.size(); i++) {
            result[i] = 0;
            for (int j = 0; j < this->_matrix[0].size(); j++) {
                result[i] += this->_matrix[i][j] * inputVector[j];
            }
        }
        return result;
    }

    void randomize() {
        for (int i = 0; i < this->_matrix.size(); i++) {
            // call randomize on each vector in the matrix
            this->_matrix[i].randomize();
        }
    }

    void print() {
        for (int i = 0; i < this->_matrix.size(); i++) {
            for (int j = 0; j < this->_matrix[0].size(); j++) {
                std::cout << this->_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void operator=(matrix<T> &matrix) {
        this->_matrix = matrix._matrix;
    }

    void operator=(matrix<T> &&matrix) {
        this->_matrix = matrix._matrix;
    }

    void add(matrix<T> &matrix) {
        for (int i = 0; i < this->_matrix.size(); i++) {
            for (int j = 0; j < this->_matrix[0].size(); j++) {
                this->_matrix[i][j] += matrix._matrix[i][j];
            }
        }
    }

    void add(T scalar) {
        for (int i = 0; i < this->_matrix.size(); i++) {
            for (int j = 0; j < this->_matrix[0].size(); j++) {
                this->_matrix[i][j] += scalar;
            }
        }
    }

};

}

#endif