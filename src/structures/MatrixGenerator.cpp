//
// Created by Lenovo on 21.10.2024.
//

#include "MatrixGenerator.h"

MatrixGenerator::MatrixGenerator(int sizeOfGeneratedMatrix, int generatedMinValue, int generatedMaxValue, bool isSymmetric)
        : sizeOfGeneratedMatrix(sizeOfGeneratedMatrix),
          generatedMinValue(generatedMinValue),
          generatedMaxValue(generatedMaxValue),
          isSymmetric(isSymmetric) {}

Matrix MatrixGenerator::generateMatrixFromFile(string filePath) {
    FileParser fileParser{};
    // Reading data from file to generate matrix
    if(fileParser.readDataFromFile(filePath)){
        cout << "file is exists and opened" << endl;
        int size = fileParser.getSizeOfMatrix();
        Matrix matrix(size, isSymmetric);
        vector<vector<int>> costsFromFile = fileParser.getCostsFromFile();
        // Iterating through matrix to set costs
        for (int i = 0; i < costsFromFile.size(); ++i) {             // traversing through the lines
            for (int j = 0; j < costsFromFile[i].size(); ++j) {       // traversing through the columns
                int cost = costsFromFile[i][j];                       // setting cost from file to selected pair of vertices
                matrix.setCost(i,j,cost);
            }
        }
        cout << "Is matrix symmetry: " << matrix.isMatrixSymmetric() << endl;
        matrix.printMatrix();
        return matrix;
    }
}

Matrix MatrixGenerator::generateRandomMatrix() {
    Matrix matrix(sizeOfGeneratedMatrix,isSymmetric);
    if(isSymmetric){
        generateSymmetricMatrix(matrix);
    }else{
        generateAsymmetricMatrix(matrix);
    }
    matrix.printMatrix();
    return matrix;

}

void MatrixGenerator::generateSymmetricMatrix(Matrix &matrix) {
    for(int i = 0; i < matrix.getSize(); i++){
        // j = i, because it generates values only for elements from the diagonal upwards of matrix where i <= j
        for(int j = i; j < matrix.getSize(); j++)
        {
            if(i == j){matrix.setCost(i,j,-1);} // setting cost to itself
            else{
                int cost = generateRandomCost();
                matrix.setCost(i,j, cost);
                matrix.setCost(j,i,cost); // setting the same cost to symmetric value from diagonal bottom part of matrix
            }
        }
    }
}

void MatrixGenerator::generateAsymmetricMatrix(Matrix &matrix) {
    for(int i = 0; i < matrix.getSize(); i++){
        for(int j = 0; j < matrix.getSize(); j++){
            if(i == j){matrix.setCost(i,j,-1);}
            else{
                matrix.setCost(i,j, generateRandomCost());
            }
        }
    }
}

int MatrixGenerator::generateRandomCost() {
    random_device randomDevice; // the object that generate random seed using random number generator on the CPU
    mt19937 gen(randomDevice()); // implementation of Mersenne Twister algorithm, which uses seed, that was generated from randomDevice
    uniform_int_distribution<> distribution(generatedMinValue,generatedMaxValue); // specified range for generated random numbers
    return distribution(gen); // generates a random integer from the specifed range using MT generator
}

