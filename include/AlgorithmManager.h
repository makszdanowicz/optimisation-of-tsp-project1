//
// Created by Lenovo on 21.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_ALGORITHMMANAGER_H
#define OPTIMISATION_OF_TSP_PROJECT1_ALGORITHMMANAGER_H
#include <iostream>
#include "Matrix.h"
#include "FileParser.h"
#include "BruteForceAlgorithm.h"
#include "NearestNeighborAlgorithm.h"
#include "RandomAlgorithm.h"
#include "chrono"
#include "MatrixGenerator.h"
#include "ConfigParser.h"
#include "string"

class AlgorithmManager {
private:
    MatrixGenerator matrixGenerator;
    string inputFilePath;
    string outputFilePath;
    string algorithmType;
    int numberOfInstance;
    void runBruteForceInstance(const Matrix& matrixFromFile);
    void runNearestNeighborInstance(const Matrix& matrixFromFile);
    void runRandomAlgorithmInstance(const Matrix& matrixFromFile);
public:
    AlgorithmManager(const ConfigParser& config);
    void runProgram();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_ALGORITHMMANAGER_H
