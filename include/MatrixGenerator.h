//
// Created by Lenovo on 21.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_MATRIXGENERATOR_H
#define OPTIMISATION_OF_TSP_PROJECT1_MATRIXGENERATOR_H


#include "Matrix.h"
#include "FileParser.h"
#include "iostream"
#include "random"

using namespace std;
class MatrixGenerator {
public:
    MatrixGenerator(int sizeOfGeneratedMatrix, int generatedMinValue, int generatedMaxValue, bool isSymmetric);
    Matrix generateMatrixFromFile(string filePath);
    Matrix generateRandomMatrix();
private:
    int sizeOfGeneratedMatrix;
    int generatedMinValue;
    int generatedMaxValue;
    bool isSymmetric;
    void generateSymmetricMatrix(Matrix &matrix);
    void generateAsymmetricMatrix(Matrix &matrix);
    int generateRandomCost();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_MATRIXGENERATOR_H
