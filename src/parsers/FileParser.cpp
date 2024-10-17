//
// Created by Lenovo on 17.10.2024.
//

#include "FileParser.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>



bool FileParser::readFile(std::string filename) {
    ifstream file(filename);
    string lineFromFile;
    if(!file.is_open()){
        cout << "Can't open a file: " << filename << endl;
        return false;
    }
    getline(file,lineFromFile); // reading the first line from file - sizeOfMatrix and writing it to lineFromFile
    string sizeOfMatrixString = lineFromFile;
    sizeOfMatrix = stoi(sizeOfMatrixString); // converting String to int
    costsFromFile.resize(sizeOfMatrix, vector<int>(sizeOfMatrix)); // initialize costs

    // Reading costs from file
    for(int i = 0; i < sizeOfMatrix; i++){
        getline(file,lineFromFile);
        istringstream ss(lineFromFile); // string stream for reading costs from line
        for(int j = 0; j < sizeOfMatrix; j++)
        {
            ss >> costsFromFile[i][j]; // reading costs from stream
        }
    }

    file.close();
    return true;
}

// get matrix of costs reference;
const vector<vector<int>> &FileParser::getCostsFromFile() const {
    return costsFromFile;
}

int FileParser::getSizeOfMatrix() const {
    return sizeOfMatrix;
}
