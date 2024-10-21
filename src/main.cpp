#include <iostream>
#include "Matrix.h"
#include "FileParser.h"
#include "BruteForceAlgorithm.h"
#include "NearestNeighborAlgorithm.h"
#include "RandomAlgorithm.h"
#include "chrono"
#include "MatrixGenerator.h"

using namespace std;
int main() {
    string basePath = "../data/";
    string fileName = "matrix_6x6.atsp";
    string filePath = basePath + fileName;
    MatrixGenerator matrixGenerator (8,0,100,1);
    Matrix matrix = matrixGenerator.generateRandomMatrix();
    //Matrix matrix = MatrixGenerator::generateMatrixFromFile(filePath);
    BruteForceAlgorithm bruteForce (matrix);
    auto start = chrono::high_resolution_clock::now(); // start of time measurement
    bruteForce.algorithmSolve();
    auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
    cout << "algorithm execution time: " << duration.count() << " ms" << endl;


    return 0;
}
