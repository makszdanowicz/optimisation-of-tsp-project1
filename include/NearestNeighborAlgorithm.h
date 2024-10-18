//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_NEARESTNEIGHBORALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_NEARESTNEIGHBORALGORITHM_H


#include "Matrix.h"
#include "vector"

using namespace std;

class NearestNeighborAlgorithm {
private:
    Matrix matrix;
public:
    NearestNeighborAlgorithm(Matrix matrix); // constructor
    void algorithmSolve();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_NEARESTNEIGHBORALGORITHM_H
