#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()


#include "matrix.h"


TwoDimensionMatrix &TwoDimensionMatrix::operator=(TwoDimensionMatrix other) {
    swap(other);
    return *this;
}

//private method for copy and swap idiom
void TwoDimensionMatrix::swap(TwoDimensionMatrix &other) noexcept {
    std::swap(matrix, other.matrix);
}

std::ostream& operator<<(std::ostream& out, const TwoDimensionMatrix& other) {
    for (size_t i = 0; i < other.size_; i++) {
        out << "{ ";
        for (size_t j = 0; j < other.size_; j++)
            out << other.matrix[i][j] << ", ";
        out << "}" << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, TwoDimensionMatrix& other) {
    for (size_t i = 0; i < other.size_; i++) {
        for (size_t j = 0; j < other.size_; j++)
            in >> other.matrix[i][j];
    }
    return in;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    TwoDimensionMatrix result(matrix1);
    for (size_t i = 0; i < matrix1.size_; i++)
        for (size_t j = 0; j < matrix1.size_; j++)
            result.matrix[i][j] += matrix2.matrix[i][j];
    return result;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement num) {
    for (size_t i = 0; i < size_; i++)
        for (size_t j = 0; j < size_; j++)
            matrix[i][j] *= num;
    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &m) const{
    TwoDimensionMatrix result;
    for (size_t i = 0; i < size_; i++)
        for (size_t j = 0; j < size_; j++)
            result.matrix[i][j] = matrix[i][j] && m.matrix[i][j];
    return result;
}