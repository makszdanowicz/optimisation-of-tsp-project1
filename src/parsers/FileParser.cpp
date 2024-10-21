//
// Created by Lenovo on 17.10.2024.
//

#include "FileParser.h"



bool FileParser::readDataFromFile(const string& filename) {
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

void FileParser::openFile(std::string filename) {
    outputFile.open(filename,ios::app); // open file in append mode
    if(!outputFile.is_open()){
        cout << "The wrong name of outputPath" << endl;
    }
}

void FileParser::saveValueToFile(double valueToSave) {
    if(outputFile.is_open()){
        outputFile << valueToSave << endl;
    }
}

void FileParser::closeFile() {
    if(outputFile.is_open()){
        outputFile.close();
    }
}