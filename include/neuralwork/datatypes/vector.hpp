#ifndef NEURALWORK_VECTOR
#define NEURALWORK_VECTOR
#include <vector>

namespace neuralwork {
// write a vector struct that internally uses std::vector
template<typename T>
struct vector {
private:
    std::vector<T> _vector;
public:
    // default constructor
    vector() {
        this->_vector = std::vector<T>(1,0);
    };
    // constructor with default value and size
    vector(T default_value, int size) {
        this->_vector = std::vector<T>(size, default_value);
    }
    // constructor with std::vector
    vector(std::vector<T> _vector) {
        this->_vector = _vector;
    }
    // constructor with array of T
    vector(T* arr, int size) {
        for (int i = 0; i < size; i++) {
            this->_vector.push_back(arr[i]);
        }
    }
    // dot product
    T dot(vector<T> other) {
        T sum = 0;
        for (int i = 0; i < this->_vector.size(); i++) {
            sum += this->_vector[i] * other._vector[i];
        }
        return sum;
    }

    // getter
    std::vector<T> get() {
        return this->_vector;
    }
    // overload [] operator
    T& operator[](int index) {
        return this->_vector[index];
    }


};
}

#endif // 
