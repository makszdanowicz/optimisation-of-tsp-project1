//
// Created by Lenovo on 21.10.2024.
//

#include "AlgorithmManager.h"

AlgorithmManager::AlgorithmManager(const ConfigParser &config)
    :matrixGenerator(config.getMatrixSize(), config.getMinValueToGenerate(), config.getMaxValueToGenerate(), config.isSymmetric1()),
    inputFilePath(config.getInputFilePath()),
    outputFilePath(config.getOutputFilePath()),
    numberOfInstance(config.getNumberOfInstance()),
    algorithmType(config.getAlgorithmType()) {}



void AlgorithmManager::runProgram() {
    Matrix matrixFromFile = matrixGenerator.generateMatrixFromFile(inputFilePath);
    if(algorithmType == "bruteForce"){
        BruteForceAlgorithm bruteForce(matrixFromFile);
        executeAlgorithm(bruteForce);
    }else if(algorithmType == "nearestNeighbor"){
        NearestNeighborAlgorithm nearestNeighbor(matrixFromFile);
        executeAlgorithm(nearestNeighbor);
    }
    else if(algorithmType == "random"){
        RandomAlgorithm randomAlgorithm(matrixFromFile);
        executeAlgorithm(randomAlgorithm);
    }
    else{cout << "wrong typed name of algorithm" << endl;}
}

void AlgorithmManager::executeAlgorithm(Algorithm &algorithm) {
    // performing test to algorithm
    algorithm.algorithmSolve();
    cout << endl;

    FileParser fileParser;
    long long arithmeticSum = 0;
    int instanceSize;
    fileParser.openFile(outputFilePath);

    for(int i = 0; i < numberOfInstance; i++){
        Matrix newMatrix = matrixGenerator.generateRandomMatrix();
        instanceSize = newMatrix.getSize();
        algorithm.setNewMatrix(newMatrix);
        cout << "ITERATION NUMBER: " << i << endl;
        auto start = chrono::high_resolution_clock::now(); // start of time measurement
        algorithm.algorithmSolve();
        auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
        long long  time = duration.count();
        arithmeticSum += time;
        cout << "algorithm execution time: " << time << " ms" << endl;
        fileParser.saveValueToFile(time);
        cout << endl;
    }
    fileParser.closeFile();
    cout << "Instance size of actual analyzing instance: " << instanceSize << endl;
    double arithmeticAverage = static_cast<double>(arithmeticSum) / numberOfInstance;
    cout << "Arithmetic average of times for a given instance size: " << arithmeticAverage << "[ms]" << endl;
}



