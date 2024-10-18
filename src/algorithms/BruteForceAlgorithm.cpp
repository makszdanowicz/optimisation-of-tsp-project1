//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/BruteForceAlgorithm.h"
#include <vector>
#include <iostream>

using namespace std;

BruteForceAlgorithm::BruteForceAlgorithm(Matrix matrix) : matrix(matrix){}

void BruteForceAlgorithm::algorithmSolve() {
    int sizeOfVertices = matrix.getSize();

    vector<int> vertices(sizeOfVertices);
    for(int i = 0; i < sizeOfVertices; i++){
        vertices[i] = i;
    }

    int bestCost = INT_MAX;
    do{
        int currentCost = 0;
        for(int i = 0; i < sizeOfVertices - 1; i++){
            int cost = matrix.getCost(vertices[i], vertices[i+1]);
            if(cost != -1){
                currentCost += cost;
            }
        }
        int returnCost = matrix.getCost(vertices[sizeOfVertices-1], vertices[0]);
        if(returnCost != -1){
            currentCost += returnCost;
        }

        if(currentCost < bestCost){
            bestCost = currentCost;
        }
    }while(isNextPermutation(vertices));
    cout << "The best cost: " << bestCost << endl;

}

bool BruteForceAlgorithm::isNextPermutation(vector<int>& vertices) {
    int size = vertices.size();
    // find the greatest and the last in vertices collection index, that is true for condition vertices[k] < vertices[k+1]
    int k = -1;
    for(int i = 0; i < size - 1; i++){
        if(vertices[i] < vertices[i+1]){
            k = i;
        }
    }

    // if there is no greatest k, it means that it is basically the last permutation
    if(k == -1){
        reverseVertices(vertices,0, size-1);
        return false;
    }

    // find the greatest and last in vertices collection index, that is true for condition vertices[k] < vertices[l]
    int l = -1;
    for(int i = k + 1; i < size; i++){
        if(vertices[k] < vertices[i]){
            l = i;
        }
    }

    if(l == -1){
        return false;
    }

    // swapping founded values
    swap(vertices[k], vertices[l]);
    // reversing collection elements after k element
    reverseVertices(vertices,k+1,size-1);
    return true; // next permutation is generated successfully
}

void BruteForceAlgorithm::reverseVertices(vector<int>& vertices, int start, int end) {
    while(start < end){
        swap(vertices[start],vertices[end]);
        start++;
        end--;
    }
}