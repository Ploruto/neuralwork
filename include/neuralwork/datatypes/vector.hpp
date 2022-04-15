#ifndef NEURALWORK_VECTOR
#define NEURALWORK_VECTOR

#include <vector>

namespace neuralwork {
template <typename T>
struct vector
{
    public:
        std::vector<T> _vector;

    public:
        vector(std::vector<T> vector)
        {
            this->_vector = vector;
        }

        vector(int size)
        {
            this->_vector = std::vector<T>(size);
        }

        vector(int size, T value)
        {
            this->_vector = std::vector<T>(size, value);
        }

        vector(int size, T *values)
        {
            this->_vector = std::vector<T>(values, values + size);
        }

        vector(const vector &vector)
        {
            this->_vector = vector._vector;
        }

        vector(vector &&vector)
        {
            this->_vector = vector._vector;
        }

        vector &operator=(const vector &vector)
        {
            this->_vector = vector._vector;
            return *this;
        }

        vector &operator=(vector &&vector)
        {
            this->_vector = vector._vector;
            return *this;
        }

        T &operator[](int index)
        {
            return this->_vector[index];
        }

        void randomize()
        {
            for (int i = 0; i < this->_vector.size(); i++)
            {
                this->_vector[i] = (float)rand() / (float)RAND_MAX;
            }
        }

        int size()
        {
            return this->_vector.size();
        }  
        
        void print()
        {
            for (int i = 0; i < this->_vector.size(); i++)
            {
                std::cout << this->_vector[i] << " ";
            }
            std::cout << std::endl;
        }
};
}



#endif