
# Optimisation of TSP Project-1
This project is a part of the course "Designing Efficient Algorithms" at Wrocław University of Science and Technology. It focuses on solving the Travelling Salesman Problem (TSP) using various algorithms with a JSON configuration file to manage parameters. CMake is used for building and managing project dependencies, including the nlohmann/json library for handling JSON files. The project is structured in a modular way to allow for easy scalability and testing of different algorithmic approaches.

## Project Description

This project implements various algorithms to solve the Travelling Salesman Problem (TSP), including:

- **Brute Force Algorithm**
- **Nearest Neighbor Algorithm**
- **Random Algorithm**

The project dynamically generates matrices to represent distances between cities and measures the execution time of each algorithm. The user can control parameters such as the number of instances, matrix size, and algorithm selection through a configuration file.

## Features

- Supports three algorithms for TSP solving:
  - **Brute Force**: Evaluates all possible permutations to find the optimal path.
  - **Nearest Neighbor**: A greedy algorithm that builds the path by selecting the nearest unvisited city.
  - **Random Algorithm**: Randomly generates paths.
  
- Configurable through a JSON configuration file.
- Generates random matrices of distances between cities.
- Records execution time for performance analysis.

## Configuration File

The project uses a JSON configuration file to control the behavior of the algorithms. The configuration file must contain the following fields:

```json
{
  "inputFilePath": "../data/matrix_8x8.atsp",   // Path to the input matrix file(to test if algorithm working correct)
  "outputFilePath": "../results/result.csv",    // Path to the output file with results
  "matrix": {                               
    "size":9,                                   // Number of cities (matrix size)   
    "minValueToGenerate" : 0,                   // Minimum distance between cities
    "maxValueToGenerate" : 100,                 // Maximum distance between cities
    "isSymmetric" : true                        // Whether the matrix should be symmetric
  },
  "algorithm": "bruteForce",                    // Algorithm to use: bruteForce, nearestNeighbor, random
  "numberOfInstance": 100,                      // Number of instances to generate
  "showProgress" : true                         // Show progress of the algorithm execution
}
```

### Fields Explanation:

- **inputFilePath:** Path to a file that contains a pre-defined matrix of distances.
- **outputFilePath:** Path to where the results will be saved.
- **size:** The number of cities in the problem (size of the matrix).
- **minValueToGenerate:** The minimum distance value when generating random distances.
- **maxValueToGenerate:** The maximum distance value.
- **isSymmetric:** If true, the distance matrix will be symmetric (i.e., dist[i][j] == dist[j][i]).
- **algorithm**: The algorithm to be used (bruteForce, nearestNeighbor, or random).
- **numberOfInstance**: The number of matrix instances to generate.
- **showProgress**: If true, the program will display the bar with progress of the algorithm during execution.

## Dependencies

The project uses the following library to handle JSON configuration files:
- **nlohmann/json:** A popular single-header JSON library for C++.
To download and link this library, the project uses CMake's FetchContent feature. The library is automatically downloaded and built into the project during the build process.

```bash
# Include FetchContent module
include(FetchContent)

# Declaration of external library to download from the git repository - nlohmann/json
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2  # Wybierz odpowiednią wersję, np. v3.11.2
)

# Downloading declared library and build it to project
FetchContent_MakeAvailable(json)

# linking json library to project
target_link_libraries(tsp nlohmann_json::nlohmann_json)
```

## Project Structure

```graphql
├── bin/
│   ├── tsp.exe                             # an executable program 
├── config/
│   ├── config.json                         # JSON configuration file with parameters for algorithm execution
├── data/                                   # Contains the input files
├── include/                       
│   ├── Algorithm.h                         # Base class for algorithms
│   ├── AlgorithmManager.h                  # Manages algorithm execution and timing
│   ├── ConfigParser.h                      # Parses the configuration file
│   ├── FileParser.h                        # Handles input/output file operations
│   ├── Matrix.h                            # Defines the Matrix class and matrix operations
│   ├── MatrixGenerator.h                   # Defines the matrix generation process
│   ├── BruteForceAlgorithm.h               # Brute force algorithm header
│   ├── NearestNeighborAlgorithm.h          # Nearest neighbor algorithm header
│   ├── RandomAlgorithm.h                   # Random algorithm header
├── results/                                # Contains generated output files
├── src/
│   ├── algorithms/
│   │   ├── AlgorithmManager.cpp            # Algorithm manager implementation
│   │   ├── BruteForceAlgorithm.cpp         # Brute force algorithm implementation
│   │   ├── NearestNeighborAlgorithm.cpp    # Nearest neighbor algorithm implementation
│   │   ├── RandomAlgorithm.cpp             # Random algorithm implementation
│   ├── parsers/
│   │   ├── ConfigParser.cpp                # Parses JSON config file
│   │   ├── FileParser.cpp                  # Handles input/output file operations
│   ├── structures/
│   │   ├── Matrix.cpp                      # Matrix class implementation
│   │   ├── MatrixGenerator.cpp             # Matrix generator implementation
└── CMakeLists.txt                          # CMake configuration file

```

## How to Build and Run

1) Ensure you have CMake (version 3.28 or newer) installed.
2) Clone the repository and navigate to the project folder:
```bash
git clone https://github.com/makszdanowicz/optimisation-of-tsp-project1.git
cd optimisation-of-tsp-project1
```
3) Build the project:
```bash
mkdir build
cd build
cmake ..
make
```

### Run
To run the program, execute the generated tsp binary. Ensure the configuration file is properly set up:

`./tsp config.json`

or if you personalized `config.json` separately just run `tsp.exe` file from console

`..\optimisation-of-tsp-project1\bin tsp.exe`
