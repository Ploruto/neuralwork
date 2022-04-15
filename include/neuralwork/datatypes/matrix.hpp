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

    // constructor with size of matrix (cols, rows)
    matrix(int cols, int rows) {
        this->_matrix = vector<vector<T>>(cols, vector<T>(rows));
    }

    // constructor with size of matrix (cols, rows) and value
    matrix(int cols, int rows, T value) {
        this->_matrix = vector<vector<T>>(cols, vector<T>(rows, value));
    }

    // constructor with size of matrix (cols, rows) and values
    matrix(int cols, int rows, T *values) {
        this->_matrix = vector<vector<T>>(cols, vector<T>(rows, values));
    }

    T &operator()(int col, int row) {
        return this->_matrix[col][row];
    }

    vector<T> &operator[](int index) {
        return this->_matrix[index];
    }

    void set(int col, int row, T value) {
        this->_matrix[col][row] = value;
    }

    void set_col(int col, vector<T> values) {
        this->_matrix[col] = values;
    }

    // get size of matrix by multiplying the size of the outer and inner vector
    int size() {
        return this->_matrix.size() * this->_matrix[0].size();
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



};

}

#endif