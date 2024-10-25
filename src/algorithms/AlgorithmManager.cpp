//
// Created by Lenovo on 21.10.2024.
//

#include "AlgorithmManager.h"


AlgorithmManager::AlgorithmManager(const ConfigParser &config)
    :matrixGenerator(config.getMatrixSize(), config.getMinValueToGenerate(), config.getMaxValueToGenerate(), config.isSymmetric1()),
    inputFilePath(config.getInputFilePath()),
    outputFilePath(config.getOutputFilePath()),
    numberOfInstance(config.getNumberOfInstance()),
    algorithmType(config.getAlgorithmType()),
    showProgress(config.isShowProgress()){}



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
    int instanceSize = 0;
    fileParser.openFile(outputFilePath);

    for(int i = 0; i < numberOfInstance; i++){
        // Generate a new random matrix for this iteration
        Matrix newMatrix = matrixGenerator.generateRandomMatrix();
        instanceSize = newMatrix.getSize();
        algorithm.setNewMatrix(newMatrix);

        // Execute the algorithm and measure execution time
        long long  time = measureExecutionTime(algorithm);

        // Summarizing total execution time
        arithmeticSum += time;

        // Save the execution time to the output file
        fileParser.saveValueToFile(time);

        outputIterationInfo(i,time);

        // Update progress bar
        if(showProgress){
            cout << endl;
            updateProgressBar(i + 1, numberOfInstance);
        }

    }
    fileParser.closeFile();
    displayResultOfInstance(arithmeticSum,instanceSize);
}

long long AlgorithmManager::measureExecutionTime(Algorithm &algorithm) {
    auto start = chrono::high_resolution_clock::now(); // start of time measurement
    algorithm.algorithmSolve();
    auto stop = chrono::high_resolution_clock::now(); // stop of time measurement
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); // calculating of the time difference
    return duration.count();
}

void AlgorithmManager::outputIterationInfo(int iterationNumber, long long executionTime) {
    cout << "ITERATION NUMBER: " << iterationNumber << endl;
    cout << "algorithm execution time: " << executionTime << " ms" << endl;
    cout << endl;
}

void AlgorithmManager::displayResultOfInstance(long long arithmeticSum, int instanceSize) {
    cout << "Instance size of actual analyzing instance: " << instanceSize << endl;
    double arithmeticAverage = static_cast<double>(arithmeticSum) / numberOfInstance;
    cout << "Arithmetic average of times for a given instance size: " << arithmeticAverage << "[ms]" << endl;
}

// Function to update the progress bar
void AlgorithmManager::updateProgressBar(int currentInstance, int totalInstances) {
    int barWidth = 100; // Width of the progress bar
    float progress = static_cast<float>(currentInstance) / totalInstances; // Calculate progress
    int pos = barWidth * progress; // Calculate position in the bar - number of '=' symbols 
    cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "="; // Filled part
        else cout << " "; // Unfilled part
    }
    cout << "] " << int(progress * 100) << " %\r"; // Print percentage
    cout << endl;
    cout.flush(); // Ensure the output is displayed immediately
}
