cmake_minimum_required(VERSION 3.28)
project(optimisation_of_tsp_project1)

# setting standard of C++
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(include)

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

# find all .cpp files in src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# create .exe file
add_executable(tsp ${SOURCES}
        src/parsers/FileParser.cpp
        include/FileParser.h
        src/structures/MatrixGenerator.cpp
        include/MatrixGenerator.h
        src/parsers/ConfigParser.cpp
        include/ConfigParser.h)

# linking json library to project
target_link_libraries(tsp nlohmann_json::nlohmann_json)
