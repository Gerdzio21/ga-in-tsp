cmake_minimum_required(VERSION 3.24)
project(PJC)

set(CMAKE_CXX_STANDARD 17)

add_executable(PJC main.cpp src/GeneticAlgorithm/Abstract/GeneticAlgorithm.cpp src/GeneticAlgorithm/Abstract/GeneticAlgorithm.h src/GeneticAlgorithm/Abstract/Generation.cpp src/GeneticAlgorithm/Abstract/Generation.h src/GeneticAlgorithm/Abstract/Genome.cpp src/GeneticAlgorithm/Abstract/Genome.h src/GeneticAlgorithm/Abstract/GeneticAlgorithmForTSP.cpp src/GeneticAlgorithm/Abstract/GeneticAlgorithmForTSP.h)
