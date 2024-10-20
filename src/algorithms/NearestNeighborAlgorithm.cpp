//
// Created by Lenovo on 17.10.2024.
//

#include "../../include/NearestNeighborAlgorithm.h"
#include <vector>
#include <iostream>

using namespace std;

NearestNeighborAlgorithm::NearestNeighborAlgorithm(Matrix matrix): matrix(matrix) {
    verticesSize = matrix.getSize();
}

void NearestNeighborAlgorithm::algorithmSolve() {
    int bestCost = INT_MAX;
    // Checking the minimal cost for travelling for each vertex
    for(int startVertex = 0; startVertex < verticesSize; startVertex++){
        vector<bool> visitedVertices(verticesSize, false); // vector of vertices, that stores information which vertex was visited
        //int totalCost = 0;
        int totalCost = calculateTotalCost(startVertex,visitedVertices);

        // add cost of returning path to total cost
        totalCost += matrix.getCost(lastVertex,startVertex);

        // add total cost of current path to best cost
        if(totalCost < bestCost){
            bestCost = totalCost;
        }
    }
    cout << "The best cost: " << bestCost << endl;

}

int NearestNeighborAlgorithm::calculateTotalCost(int startVertex, vector<bool> &visitedVertices) {
    int totalCost = 0;
    int currentVertex = startVertex;
    visitedVertices[currentVertex] = true; // adding current vertex to list of visited vertices

    // checking costs of unvisited neighbors of the current Vertex to find the nearest neighbor -> after find shortestPath, go to find another closet neighbor to new one
    for(int amountOfVerticesToVisit = 1; amountOfVerticesToVisit < verticesSize; amountOfVerticesToVisit++){
        int nearestNeighbor = findNearestNeighbor(currentVertex, visitedVertices);
        // if there is the closest neighbor, add information about it path
        if(nearestNeighbor != -1){
            visitedVertices[nearestNeighbor] = true;
            totalCost += matrix.getCost(currentVertex,nearestNeighbor);
            currentVertex = nearestNeighbor; // after add the shortest path, change actual vertex to found neighbor
            lastVertex = currentVertex;
        }
    }
    return totalCost;
}

int NearestNeighborAlgorithm::findNearestNeighbor(int currentVertex, vector<bool> &visitedVertices) {
    int minCost = INT_MAX;
    int nearestNeighbor = -1;
    for(int neighbor = 0; neighbor < verticesSize; neighbor++){
        int cost = matrix.getCost(currentVertex,neighbor);
        // checking is it currentCost is the shortest cost to neighbor for current vertex
        if(!visitedVertices[neighbor] && cost > -1 && cost < minCost){
            minCost = cost;
            nearestNeighbor = neighbor;
        }
    }
    return nearestNeighbor;
}
