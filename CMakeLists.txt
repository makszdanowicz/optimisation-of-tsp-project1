cmake_minimum_required(VERSION 3.28)
project(optimisation_of_tsp_project1)

# setting standard of C++
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(include)

#add_executable(tsp ../src/main.cpp
#        src/structures/Matrix.cpp)

# find all .cpp files in src directory
file(GLOB_RECURSE SOURCES "src/*.cpp")

# create .exe file
add_executable(tsp ${SOURCES}
        src/parsers/FileParser.cpp
        include/FileParser.h)


