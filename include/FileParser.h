//
// Created by Lenovo on 17.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H
#define OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H

#include "vector"
#include "string"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class FileParser {
private:
    vector<vector<int>> costsFromFile;
    int sizeOfMatrix;
    ofstream outputFile; // File stream for output

public:

    bool readDataFromFile(const string& filename);

    void openFile(string filename);
    void saveValueToFile(double valueToSave);
    void closeFile();


    const vector<vector<int>> &getCostsFromFile() const;

    int getSizeOfMatrix() const;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_FILEPARSER_H
