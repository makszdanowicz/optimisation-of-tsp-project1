#include <iostream>
#include "Matrix.h"
#include "FileParser.h"
#include "BruteForceAlgorithm.h"
#include "NearestNeighborAlgorithm.h"

using namespace std;
int main() {
    int size;
    FileParser fileParser{};

    string basePath = "../data/";
    string fileName = "matrix_11x11.atsp";
    string filePath = basePath + fileName;
    bool isSymmetric = 0;
    if(fileParser.readFile(filePath)){
        cout << "file is exists and opened" << endl;
        size = fileParser.getSizeOfMatrix();
        Matrix matrix(size, isSymmetric);
        vector<vector<int>> costsFromFile = fileParser.getCostsFromFile();
        // Iterowanie przez macierz
        for (int i = 0; i < costsFromFile.size(); ++i) {             // Przechodzenie przez wiersze
            for (int j = 0; j < costsFromFile[i].size(); ++j) {       // Przechodzenie przez kolumny
                int cost = costsFromFile[i][j];                       // Pobranie wartości (kosztu)
                matrix.setCost(i,j,cost);
            }
        }
        cout << "Is matrix symmetry: " << matrix.isMatrixSymmetric() << endl;
        matrix.printMatrix();
//        BruteForceAlgorithm bruteForce (matrix);
//        bruteForce.algorithmSolve();
        NearestNeighborAlgorithm nearestNeighbor(matrix);
        nearestNeighbor.algorithmSolve();
    }

    return 0;
}
