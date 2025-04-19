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