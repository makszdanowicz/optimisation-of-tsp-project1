//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/Matrix.h"
#include <iostream>

using namespace std;
Matrix::Matrix(int size, bool type) {
    this->size = size;
    costs = new int*[size]; // creating array of pointers to line
    for(int i = 0; i < size; i++){
        costs[i] = new int[size]; // for each line creating an array
    }
    isSymmetric = type;

    // initialization of costs array with '0' values
    for(int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            costs[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    // free up the memory space occupied by the array of costs
    for(int i = 0; i < size; i++){
        delete[] costs[i];
    }
    delete[] costs;
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

