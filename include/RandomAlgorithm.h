//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H


#include "Matrix.h"

class RandomAlgorithm {
private:
    Matrix matrix;
    int randomGenerator();
public:
    RandomAlgorithm(Matrix matrix);
    int generateVertex();
    void algorithmSolve();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
