#include <iostream>
#include "Matrix.h"
#include "FileParser.h"

using namespace std;
int main() {
    int size;
    FileParser fileParser{};

    string basePath = "../data/";
    string fileName = "matrix_6x6.atsp";
    string filePath = basePath + fileName;

    if(fileParser.readFile(filePath)){
        cout << "file is exists and opened" << endl;
        size = fileParser.getSizeOfMatrix();
        Matrix matrix(size, false);
        vector<vector<int>> costsFromFile = fileParser.getCostsFromFile();
        // Iterowanie przez macierz
        for (int i = 0; i < costsFromFile.size(); ++i) {             // Przechodzenie przez wiersze
            for (int j = 0; j < costsFromFile[i].size(); ++j) {       // Przechodzenie przez kolumny
                int cost = costsFromFile[i][j];                       // Pobranie wartości (kosztu)
                matrix.setCost(i,j,cost);
            }
        }
        matrix.printMatrix();
    }

    /*
    // initialiation matrix vith values
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j)
            {
                matrix.setCost(i,j, -1);
            }
            else{
                matrix.setCost(i,j,5);
            }
        }
    }
    cout << "Type of matrix: " << matrix.isMatrixSymmetric() << endl;
    matrix.printMatrix();
     */


    return 0;
}
