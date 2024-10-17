//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H
#define OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H

#include "vector"
#include "string"

using namespace std;

class FileParser {
private:
    vector<vector<int>> costsFromFile;
    int sizeOfMatrix;

public:

    bool readFile(string filename);

    const vector<vector<int>> &getCostsFromFile() const;

    int getSizeOfMatrix() const;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H
