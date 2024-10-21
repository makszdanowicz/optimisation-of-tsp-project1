//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H


#include "Matrix.h"
#include "vector"

class RandomAlgorithm {
private:
    Matrix matrix;
    int verticesSize;
    int randomGenerateVertex();
    int findNotVisitedVertex(int startVertex,vector<bool>& isVisitedVertex);

public:
    explicit RandomAlgorithm(Matrix matrix);
    void algorithmSolve();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
