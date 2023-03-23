cmake_minimum_required(VERSION 3.24)
project(PJC)

set(CMAKE_CXX_STANDARD 17)

add_executable(PJC main.cpp src/GeneticAlgorithm/GeneticAlgorithm.cpp src/GeneticAlgorithm/GeneticAlgorithm.h src/GeneticAlgorithm/Generation.cpp src/GeneticAlgorithm/Generation.h src/GeneticAlgorithm/Genome.cpp src/GeneticAlgorithm/Genome.h src/GeneticAlgorithm/GeneticAlgorithmForTSP.cpp src/GeneticAlgorithm/GeneticAlgorithmForTSP.h)
