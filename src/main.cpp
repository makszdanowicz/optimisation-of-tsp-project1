#include <iostream>
#include "Matrix.h"
#include "FileParser.h"
#include "BruteForceAlgorithm.h"
#include "NearestNeighborAlgorithm.h"
#include "RandomAlgorithm.h"
#include "chrono"
#include "MatrixGenerator.h"
#include "ConfigParser.h"

using namespace std;
int main() {
    ConfigParser configParser("../config/config.json");
    if(configParser.readConfig()){

        string inputFilePath = configParser.getInputFilePath();
        string outputFilePath = configParser.getOutputFilePath();
        int matrixSize = configParser.getMatrixSize();
        int minValueToGenerate = configParser.getMinValueToGenerate();
        int maxValueToGenerate = configParser.getMaxValueToGenerate();
        bool isSymmetric = configParser.isSymmetric1();
        string algorithmType = configParser.getAlgorithmType();
        int numberOfInstance = configParser.getNumberOfInstance();

        MatrixGenerator matrixGenerator (matrixSize,minValueToGenerate, maxValueToGenerate, isSymmetric);
        Matrix matrixFromFile = matrixGenerator.generateMatrixFromFile(inputFilePath);

        BruteForceAlgorithm bruteForce (matrixFromFile);
        bruteForce.algorithmSolve();
        cout << endl;

        for(int i = 0; i < numberOfInstance; i++){
            Matrix newMatrix = matrixGenerator.generateRandomMatrix();
            bruteForce.setNewMatrix(newMatrix);
            auto start = chrono::high_resolution_clock::now(); // start of time measurement
            bruteForce.algorithmSolve();
            auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
            auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
            cout << "algorithm execution time: " << duration.count() << " ms" << endl;
            cout << endl;
        }

    }else{
        cout << "Failed to read configuration file" << endl;

    }
    return 0;
}
