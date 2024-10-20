//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_BRUTEFORCEALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_BRUTEFORCEALGORITHM_H


#include "Matrix.h"
#include "vector"

using namespace std;

class BruteForceAlgorithm {
private:
    Matrix matrix;
    int verticesSize;
    vector<int> vertices;
    vector<int> generateVertices();
    bool isNextPermutation();
    void reverseVertices(vector<int>& vertices, int start, int end);
    int findLargestK();
    int findLargestL(int k);
public:
    explicit BruteForceAlgorithm(Matrix matrix); // constructor
    void algorithmSolve();
};




#endif //OPTIMISATION_OF_TSP_PROJECT1_BRUTEFORCEALGORITHM_H
