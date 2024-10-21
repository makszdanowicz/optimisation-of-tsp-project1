//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/BruteForceAlgorithm.h"
#include <vector>
#include <iostream>

using namespace std;

BruteForceAlgorithm::BruteForceAlgorithm(Matrix matrix) : matrix(matrix){
    verticesSize = matrix.getSize();
    vertices = generateVertices();
}

void BruteForceAlgorithm::setNewMatrix(const Matrix& newMatrix) {
    this->matrix = newMatrix; // actualizing matrix
    this->verticesSize = matrix.getSize();  // actualizing vertices size
    this->vertices = generateVertices();    // actualizing vertices list
}

void BruteForceAlgorithm::algorithmSolve() {
    int bestCost = INT_MAX;
    do{
        int currentCost = 0;
        for(int i = 0; i < verticesSize - 1; i++){
            int cost = matrix.getCost(vertices[i], vertices[i+1]);
            if(cost != -1){
                currentCost += cost;
            }
        }
        int returnCost = matrix.getCost(vertices[verticesSize-1], vertices[0]);
        if(returnCost != -1){
            currentCost += returnCost;
        }

        if(currentCost < bestCost){
            bestCost = currentCost;
        }
    }while(isNextPermutation());
    cout << "The best cost: " << bestCost << endl;

}

bool BruteForceAlgorithm::isNextPermutation() {

    // find the greatest and the last in vertices collection index, that is true for condition vertices[k] < vertices[k+1]
    int k = findLargestK();

    // if there is no greatest k, it means that it is basically the last permutation
    if(k == -1){
        reverseVertices(vertices,0, verticesSize - 1);
        return false;
    }

    // find the greatest and last in vertices collection index, that is true for condition vertices[k] < vertices[l]
    int l = findLargestL(k);

    if(l == -1){
        return false;
    }

    // swapping founded values
    swap(vertices[k], vertices[l]);
    // reversing collection elements after k element
    reverseVertices(vertices,k+1,verticesSize - 1);
    return true; // next permutation is generated successfully
}

int BruteForceAlgorithm::findLargestK() {
    int k = -1;
    for(int i = 0; i < verticesSize - 1; i++){
        if(vertices[i] < vertices[i+1]){
            k = i;
        }
    }
    return k;
}

int BruteForceAlgorithm::findLargestL(int k) {
    int l = -1;
    for(int i = k + 1; i < verticesSize; i++){
        if(vertices[k] < vertices[i]){
            l = i;
        }
    }
    return l;
}

void BruteForceAlgorithm::reverseVertices(vector<int>& vertices, int start, int end) {
    while(start < end){
        swap(vertices[start],vertices[end]);
        start++;
        end--;
    }
}

vector<int> BruteForceAlgorithm::generateVertices() {
    vector<int> vertices(verticesSize);
    for(int i = 0; i < verticesSize; i++){
        vertices[i] = i;
    }
    return vertices;
}