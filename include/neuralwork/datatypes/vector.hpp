#ifdef NEURALWORK_VECTOR
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
      vector() {};
      // constructor with std::vector
      vector(std::vector<T> _vector) {
        this->_vector = data;
      }
      // constructor with array of T
      vector(T* _vector, int size) {
        for (int i = 0; i < size; i++) {
          this->_vector.push_back(data[i]);
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
  }
}

#endif // 
