//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H

#include "Algorithm.h"
#include "Matrix.h"
#include "vector"
#include "iostream"
#include "random"

class RandomAlgorithm : public Algorithm{
private:
    Matrix matrix;
    int verticesSize;
    int randomGenerateVertex();
    int findNotVisitedVertex(int startVertex,vector<bool>& isVisitedVertex);

public:
    explicit RandomAlgorithm(Matrix matrix);
    void setNewMatrix(const Matrix& newMatrix) override;
    void algorithmSolve() override;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_RANDOMALGORITHM_H
