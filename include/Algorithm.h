//
// Created by Lenovo on 21.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_ALGORITHM_H
#define OPTIMISATION_OF_TSP_PROJECT1_ALGORITHM_H
#include "Matrix.h"

class Algorithm {
public:
    virtual void algorithmSolve() = 0;
    virtual void setNewMatrix(const Matrix& newMatrix) = 0;
    virtual ~Algorithm() = default;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_ALGORITHM_H
