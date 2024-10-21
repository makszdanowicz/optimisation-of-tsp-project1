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
        runBruteForceInstance(matrixFromFile);
    }else if(algorithmType == "nearestNeighbor"){
        runNearestNeighborInstance(matrixFromFile);
    }
    else if(algorithmType == "randomAlgorithm"){
        runRandomAlgorithmInstance(matrixFromFile);
        RandomAlgorithm randomAlgorithm (matrixFromFile);
        randomAlgorithm.algorithmSolve();
        cout << endl;
    }
}

void AlgorithmManager::runBruteForceInstance(const Matrix& matrixFromFile) {
    // performing test
    BruteForceAlgorithm bruteForce(matrixFromFile);
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
}

void AlgorithmManager::runNearestNeighborInstance(const Matrix& matrixFromFile) {
    // performing test
    NearestNeighborAlgorithm nearestNeighbor(matrixFromFile);
    nearestNeighbor.algorithmSolve();
    cout << endl;
    for(int i = 0; i < numberOfInstance; i++){
        Matrix newMatrix = matrixGenerator.generateRandomMatrix();
        nearestNeighbor.setNewMatrix(newMatrix);
        auto start = chrono::high_resolution_clock::now(); // start of time measurement
        nearestNeighbor.algorithmSolve();
        auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
        cout << "algorithm execution time: " << duration.count() << " ms" << endl;
        cout << endl;

    }

}

void AlgorithmManager::runRandomAlgorithmInstance(const Matrix& matrixFromFile) {
    // performing test
    RandomAlgorithm randomAlgorithm(matrixFromFile);
    randomAlgorithm.algorithmSolve();
    cout << endl;
    for(int i = 0; i < numberOfInstance; i++){
        Matrix newMatrix = matrixGenerator.generateRandomMatrix();
        randomAlgorithm.setNewMatrix(newMatrix);
        auto start = chrono::high_resolution_clock::now(); // start of time measurement
        randomAlgorithm.algorithmSolve();
        auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
        cout << "algorithm execution time: " << duration.count() << " ms" << endl;
        cout << endl;
    }

}


