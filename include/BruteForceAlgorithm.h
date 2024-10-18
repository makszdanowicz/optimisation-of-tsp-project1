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
public:
    BruteForceAlgorithm(Matrix matrix); // constructor
    void algorithmSolve();
    bool isNextPermutation(vector<int>& vertices);
    void reverseVertices(vector<int>& vertices, int start, int end);
};




#endif //OPTIMISATION_OF_TSP_PROJECT1_BRUTEFORCEALGORITHM_H
