//
// Created by Lenovo on 21.10.2024.
//

#ifndef OPTIMISATION_OF_TSP_PROJECT1_CONFIGPARSER_H
#define OPTIMISATION_OF_TSP_PROJECT1_CONFIGPARSER_H
#include "string"
#include "iostream"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;
class ConfigParser {
private:
    string configPath;
    string inputFilePath;
    string outputFilePath;
    int matrixSize;
    int minValueToGenerate;
    int maxValueToGenerate;
    bool isSymmetric;
    string algorithmType;
    int numberOfInstance;
public:
    explicit ConfigParser(const string &configPath);
    bool readConfig();
    const string &getInputFilePath() const;
    const string &getOutputFilePath() const;
    int getMatrixSize() const;
    int getMinValueToGenerate() const;
    int getMaxValueToGenerate() const;
    bool isSymmetric1() const;
    const string &getAlgorithmType() const;
    int getNumberOfInstance() const;
};


#endif //OPTIMISATION_OF_TSP_PROJECT1_CONFIGPARSER_H
