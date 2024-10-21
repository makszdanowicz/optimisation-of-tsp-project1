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
    int verticesSize;
    int lastVertex;
    int findNearestNeighbor(int currentVertex, vector<bool>& visitedVertices);
    int calculateTotalCost(int startVertex, vector<bool>& visitedVertices);
public:
    explicit NearestNeighborAlgorithm(Matrix matrix); // constructor
    void setNewMatrix(const Matrix& newMatrix);
    void algorithmSolve();
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_NEARESTNEIGHBORALGORITHM_H
