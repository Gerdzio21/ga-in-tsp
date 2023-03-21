cmake_minimum_required(VERSION 3.24)
project(PJC)

set(CMAKE_CXX_STANDARD 17)

add_executable(PJC main.cpp cmake-build-debug/GeneticAlgorithm.cpp cmake-build-debug/GeneticAlgorithm.h cmake-build-debug/Generation.cpp cmake-build-debug/Generation.h cmake-build-debug/Genome.cpp cmake-build-debug/Genome.h GeneticAlgorithmForTSP.cpp GeneticAlgorithmForTSP.h)
