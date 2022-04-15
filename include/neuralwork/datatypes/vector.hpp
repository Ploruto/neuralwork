#ifndef NEURALWORK_VECTOR
#define NEURALWORK_VECTOR

#include <vector>
#include <iostream>


namespace neuralwork{
template<typename T>
struct vector {
private:
    std::vector<T> _v;
    int _size;
    void _equalSizeCheck(vector<T> &v) {
        if (!this->isEqualSize(v)) {
            throw std::invalid_argument("Vectors are of unequal size");
        }
    }

public:
    // defining the constructor
    vector() {
        this->_size = 0;
        this->_v = std::vector<T>({});
    }

    vector(const T arr[], const int &length) {
        this->_size = length;
        this->_v = std::vector<T>(length);
        for (int i = 0; i < length; i++) {
            this->_v[i] = arr[i];
        }
    }

    // vec(vec<T> &v){
    //     this->_v = std::vector<T>(v.getVector());
    //     this->_size = v.getSize();
    // }

    vector(std::vector<T> &v) {
        this->_v = std::vector<T>(v);
        this->_size = v.size();
    }

    vector(const int size, const T defaultValue = 0) {
        this->_size = size;
        this->_v = std::vector<T>(size, defaultValue);
    }

    // defining the getter
    std::vector<T> getVector() const {
        return this->_v;
    }

    int getSize() {
        return this->_size;
    }

    // defining the setter
    void setAt(const int &index, const T value) {
        this->_v[index] = value;
    }

    void setVector(vector<T> &v) {
        this->_v = std::vector<T>(v.getVector());
        this->_size = v.getSize();
    }

    // defining the operator overloading
    void operator=(vector<T> &v) {
        this->_v = std::vector<T>(v.getVector());
        this->_size = v.getSize();
    }

    T operator[](const int &index) { // works only as a getter
        return this->_v[index];
    }

    vector<T> operator+(vector<T> &v) { // adding two vectors
        this->_equalSizeCheck(v);
        vector<T> result(this->_size);
        for (int i = 0; i < this->_size; i++) {
            result.setAt(i, this->_v[i] + v[i]);
        }
        return result;
    }

    T operator*(vector<T> &v) { // dot product
        this->_equalSizeCheck(v);
        T sum = 0;
        for (int i = 0; i < this->_size; i++) {
            sum += v[i] * (*this)[i];
        }
        return sum;
    }

    vector<T> operator*(const T &scalar) { // scalar multiplication
        vector<T> result(this->_size);
        for (int i = 0; i < this->_size; i++) {
            result.setAt(i, this->_v[i] * scalar);
        }
        return result;
    }

    // defining other methods
    void push_back(T el) {
        this->_v.push_back(el);
        (this->_size)++;
    }

    void randomize() {
        for (int i = 0; i < this->_size; i++) {
            this->_v[i] = ((float) rand() / (RAND_MAX));
        }
    }

    bool isEqualSize(vector<T> &v) {
        return this->_size == v.getSize();
    }

    void print() {
        for (int i = 0; i < this->_size; i++) {
            std::cout<<this->_v[i]<<" ";
        }
        std::cout<<std::endl;
    }
};
}

#endif