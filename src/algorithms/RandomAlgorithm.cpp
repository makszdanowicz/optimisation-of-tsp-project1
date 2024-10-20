//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/RandomAlgorithm.h"
#include "vector"
#include "iostream"
#include "random"

using namespace std;

RandomAlgorithm::RandomAlgorithm(Matrix matrix) : matrix(matrix){
    verticesSize = matrix.getSize();
}

void RandomAlgorithm::algorithmSolve() {
    // Initializing algorithm values
    vector<bool> isVisitedVertex(verticesSize, false); // contain vertices that is considered and can't be used again in algorithm
    int pathCost = 0;
    int firstVertex = randomGenerator(); // Randomly generate start vertex and add it to visited list
    int startVertex = firstVertex;
    isVisitedVertex[startVertex] = true;

    // find random path and count cost
    for(int i = 1; i < verticesSize; i++){
        int currentVertex = findNotVisitedVertex(startVertex,isVisitedVertex);
        pathCost += matrix.getCost(startVertex,currentVertex);
        isVisitedVertex[currentVertex] = true;
        startVertex = currentVertex;
    }
    // add cost of returning path to total cost
    pathCost+=matrix.getCost(startVertex,firstVertex);
    cout << "Shortest path: " << pathCost << endl;

}

int RandomAlgorithm::findNotVisitedVertex(int startVertex,vector<bool>& isVisitedVertex) {
    // reset actual vertex and cost
    int currentVertex = -1;
    int cost = 0;
    // find using random not-visited yet vertex
    while(currentVertex == -1){
        int potentialVertex = randomGenerator();
        // checking conditions, that vertex is not visited and don't have cost -1(it means it goes into itself)
        if(!isVisitedVertex[potentialVertex]){
            cost = matrix.getCost(startVertex,potentialVertex);
            if(cost != -1){currentVertex = potentialVertex;}
        }
    }
    return currentVertex;

}

int RandomAlgorithm::randomGenerator() {
    random_device randomDevice; // the object that generate random seed using random number generator on the CPU
    mt19937 gen(randomDevice()); // implementation of Mersenne Twister algorithm, which uses seed, that was generated from randomDevice
    uniform_int_distribution<> distribution(0,matrix.getSize() - 1); // specified range for generated random numbers
    return distribution(gen); // generates a random integer from the specifed range using MT generator
}


