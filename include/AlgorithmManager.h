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
    bool showProgress;
    void executeAlgorithm(Algorithm& algorithm);
    long long measureExecutionTime(Algorithm& algorithm);
    void outputIterationInfo(int iterationNumber, long long executionTime);
    void displayResultOfInstance(long long arithmeticSum, int instanceSize);
    void updateProgressBar(int currentInstance, int totalInstances);


public:
    AlgorithmManager(const ConfigParser& config);
    void runProgram();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_ALGORITHMMANAGER_H
