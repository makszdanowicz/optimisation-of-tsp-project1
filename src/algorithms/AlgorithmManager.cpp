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
    fileParser.openFile(outputFilePath);
    for(int i = 0; i < numberOfInstance; i++){
        Matrix newMatrix = matrixGenerator.generateRandomMatrix();
        algorithm.setNewMatrix(newMatrix);
        auto start = chrono::high_resolution_clock::now(); // start of time measurement
        algorithm.algorithmSolve();
        auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
        cout << "algorithm execution time: " << duration.count() << " ms" << endl;
        fileParser.saveValueToFile(duration.count());
        cout << endl;
    }
    fileParser.closeFile();
}



