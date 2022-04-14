#ifndef JOPHO_MATRIX
#define JOPHO_MATRIX

#include <neuralwork/datatypes/vector.hpp>
//#include <vector>

namespace neuralwork {
template<typename T> // T may be one of the following: int, float, double, char, etc.
struct matrix{
    private:
    std::vector<vector<T>> _m; // _m is a vector of vectors indexed by _m[row][column]
    int _rows;
    int _cols;
    void _equalSizeCheck(matrix<T> &m){
        if (!this->isEqualSize(m)){
            throw std::invalid_argument("Matrices are of unequal size");
        }
    }

    public:
    // defining the constructor
    matrix(const T arr[], const int &rows, const int &cols){
        this->_rows = rows;
        this->_cols = cols;
        this->_m = std::vector<vector<T>>(rows);
        for (int i = 0; i < rows; i++){
            this->_m[i].setVector(vector<T>(arr + i * cols, cols));
        }
    }

    matrix(matrix<T> &m){
        this->_m = std::vector<vector<T>>(m.getMatrix());
        this->_rows = m.getRows();
        this->_cols = m.getCols();
    }

    matrix(std::vector<vector<T>> &m){
        this->_m = std::vector<vector<T>>(m);
        this->_rows = m.size();
        this->_cols = m[0].getSize();
    }

    matrix(const int &rows, const int &cols){
        this->_rows = rows;
        this->_cols = cols;
        this->_m = std::vector<vector<T>>(rows);
        for (int i = 0; i < rows; i++){
            this->_m.setRow(i, vector<T>(cols));
        }
    }

    // defining the getter
    std::vector<vector<T>> getMatrix() const{
        return this->_m;
    }

    int getRows(){
        return this->_rows;
    }

    int getCols(){
        return this->_cols;
    }

    // defining the setter
    void setAt(const int &row, const int &col, const T &value){
        this->_m[row][col] = value;
    }

    void setRow(const int &row, vector<T> &v){
        this->_m[row] = v;
    }


    // defining the operator overloading
    void operator=(matrix<T> &m){
        this->_m = std::vector<vector<T>>(m.getMatrix());
        this->_rows = m.getRows();
        this->_cols = m.getCols();
    }
    
    vector<T> operator[](const int &row){ // works only as a getter
        return this->_m[row];
    }

    matrix<T> operator+(matrix<T> &m){ // adding two matrices
        this->_equalSizeCheck(m);
        matrix<T> result(this->_rows, this->_cols);
        for (int i = 0; i < this->_rows; i++){
            for (int j = 0; j < this->_cols; j++){
                result.setAt(i, j, this->_m[i][j] + m(i, j));
            }
        }
        return result;	
    }

    matrix<T> operator*(matrix<T> &m){ // multiplying two matrices
        this->_equalSizeCheck(m);
        matrix<T> result(this->_rows, m.getCols());
        for (int i = 0; i < this->_rows; i++){
            for (int j = 0; j < m.getCols(); j++){
                result.setAt(i, j, this->_m[i][0] * m(0, j));
                for (int k = 1; k < this->_cols; k++){
                    result.setAt(i, j, result(i, j) + this->_m[i][k] * m(k, j));
                }
            }
        }
        return result;
    }

    matrix<T> operator*(const T &value){ // multiplying a matrix by a scalar
        matrix<T> result(this->_rows, this->_cols);
        for (int i = 0; i < this->_rows; i++){
            for (int j = 0; j < this->_cols; j++){
                result.setAt(i, j, this->_m[i][j] * value);
            }
        }
        return result;
    }

    //defining other methods
    void randomize() {
        for (int i = 0; i < this->_rows; i++) {
            this->_m[i].randomize();
        }
    }

    bool isEqualSize(matrix<T> &m){
        return (this->_rows == m.getRows() && this->_cols == m.getCols());
    }

    void print(){
        for (int i = 0; i < this->_rows; i++){
            for (int j = 0; j < this->_cols; j++){
                std::cout<<this->_m[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    // void printToFile(const char *filename){
    //     std::ofstream file(filename);
    //     for (int i = 0; i < this->_rows; i++){
    //         for (int j = 0; j < this->_cols; j++){
    //             file<<this->_m[i][j]<<" ";
    //         }
    //         file<<std::endl;
    //     }
    //     file.close();
    // }
};   
}

#endif