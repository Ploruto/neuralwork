#ifndef NEURALWORK_MATRIX
#define NEURALWORK_MATRIX

#include <neuralwork/datatypes/vector.hpp>

namespace neuralwork
{
template<typename T>
struct matrix
{
private:
    std::vector<vector<T> > _matrix;
public:
    // default constructor
    matrix() {
        this->_matrix = std::vector<vector<T>>(1,vector<T>());
    };
    // constructor with std::vector
    matrix(std::vector<vector<T>> _matrix) {
        this->_matrix = _matrix;
    }
    // constructor with array of T
    matrix(T* arr, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            this->_matrix.push_back(vector<T>(arr + i * cols, cols));
        }
    }
    // dot product
    matrix<T> dot(matrix<T> other) {
        matrix<T> result(this->_matrix.size(), other._matrix[0].size());
        for (int i = 0; i < this->_matrix.size(); i++) {
            for (int j = 0; j < other._matrix[0].size(); j++) {
                result._matrix[i][j] = this->_matrix[i].dot(other._matrix[j]);
            }
        }
        return result;
    }
    // getter
    std::vector<vector<T>> get() {
        return this->_matrix;
    }
    // overload [] operator
    vector<T>& operator[](int index) {
        return this->_matrix[index];
    }
};

} // namespace neuralwork



#endif // !NEURALWORK_MATRIX
