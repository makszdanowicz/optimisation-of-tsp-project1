//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_MATRIX_H
#define OPTIMISATION_OF_TSP_PROJECT1_MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

class Matrix {
private:
    int size;
    bool isSymmetric;
    vector<vector<int>> costs;

public:
    Matrix(int size, bool isSymmetric); // constructor
    ~Matrix(); // destructor
    int getCost(int lineIndex, int columnIndex);
    int getSize();
    void setCost(int lineIndex, int columnIndex, int cost);
    void printMatrix();
    bool isMatrixSymmetric() const;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_MATRIX_H
