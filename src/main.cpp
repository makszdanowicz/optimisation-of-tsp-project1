#include <iostream>
#include "ConfigParser.h"
#include "AlgorithmManager.h"

using namespace std;
int main() {
    ConfigParser configParser("../config/config.json");
    if(configParser.readConfig()){
        AlgorithmManager algorithmManager(configParser);
        algorithmManager.runProgram();
    }else{
        cout << "Failed to read configuration file" << endl;

    }
    return 0;
}
