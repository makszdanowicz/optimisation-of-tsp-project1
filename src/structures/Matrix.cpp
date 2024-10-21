//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/Matrix.h"

using namespace std;
Matrix::Matrix(int size, bool type) : size(size), isSymmetric(type), costs(size, std::vector<int>(size, 0)) {
}

Matrix::~Matrix() {
}

int Matrix::getCost(int lineIndex, int columnIndex) {
    return costs[lineIndex][columnIndex];
}

int Matrix::getSize() {
    return size;
}

void Matrix::setCost(int lineIndex, int columnIndex, int cost) {
    if(lineIndex > -1  && lineIndex < size && columnIndex > -1 && columnIndex < size)
    {
        costs[lineIndex][columnIndex] = cost;
        // checking is it symmetric matrix
        if(isSymmetric && lineIndex != columnIndex){
            costs[columnIndex][lineIndex] = cost;
        }
    }
}

bool Matrix::isMatrixSymmetric() const {
    return isSymmetric;
}

void Matrix::printMatrix() {
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << costs[i][j] << " ";
        }
        cout << endl;
    }
}

