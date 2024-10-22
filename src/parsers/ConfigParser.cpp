//
// Created by Lenovo on 21.10.2024.
//

#include "ConfigParser.h"

ConfigParser::ConfigParser(const string &configPath) : configPath(configPath) {}

bool ConfigParser::readConfig() {
    ifstream configFile(configPath);
    if (!configFile.is_open()) {
        cerr << "Failed to open config file: " << configPath << endl;
        return false;
    }

    try {
        json j; // object that keeps data from config file
        configFile >> j; // read data from file and write it to json object

        // using method .at() for access to key from .json file and .get(type) to convert to specified data type
        inputFilePath = j.at("inputFilePath").get<string>();
        outputFilePath = j.at("outputFilePath").get<string>();
        matrixSize = j.at("matrix").at("size").get<int>();
        minValueToGenerate = j.at("matrix").at("minValueToGenerate").get<int>();
        maxValueToGenerate = j.at("matrix").at("maxValueToGenerate").get<int>();
        isSymmetric = j.at("matrix").at("isSymmetric").get<bool>();
        algorithmType = j.at("algorithm").get<string>();
        numberOfInstance = j.at("numberOfInstance").get<int>();
        showProgress = j.at("showProgress").get<bool>();

    } catch (json::exception& e) {
        cerr << "JSON parsing error: " << e.what() << endl;
        return false;
    }

    return true;
}


const string &ConfigParser::getInputFilePath() const {
    return inputFilePath;
}

const string &ConfigParser::getOutputFilePath() const {
    return outputFilePath;
}

int ConfigParser::getMatrixSize() const {
    return matrixSize;
}

int ConfigParser::getMinValueToGenerate() const {
    return minValueToGenerate;
}

int ConfigParser::getMaxValueToGenerate() const {
    return maxValueToGenerate;
}

bool ConfigParser::isSymmetric1() const {
    return isSymmetric;
}

const string &ConfigParser::getAlgorithmType() const {
    return algorithmType;
}

int ConfigParser::getNumberOfInstance() const {
    return numberOfInstance;
}

bool ConfigParser::isShowProgress() const {
    return showProgress;
}

