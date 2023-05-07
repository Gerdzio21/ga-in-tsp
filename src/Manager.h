//
// Created by gerdzio21 on 07.05.2023.
//

#ifndef PJC_MANAGER_H
#define PJC_MANAGER_H


#include "Graph/Graph.h"
#include "Graph/Maze2D.h"
#include "UnknownMazeCreationAlgorithmException.h"
#include "Graph/KruskalMaze.h"
#include "Graph/RandKruskalMaze.h"

class Manager {
    Graph* graph;
public:
    static Maze2D* selectMazeCreationAlgorithm(int width, int height, int markingProb){
        try{
            return new KruskalMaze(width, height, markingProb);
        }catch(std::exception &e){
            throw UnknownMazeCreationAlgorithmException();
        }

    }
    static Maze2D* selectMazeCreationAlgorithm(int width, int height, int markingProb, int breakThroughProb){
        try{
            return new RandKruskalMaze(width, height, markingProb, breakThroughProb);
        }catch(std::exception &e){
            throw UnknownMazeCreationAlgorithmException();
        }
    }
    void createGraph(Maze2D* maze2D){
        graph = maze2D;
    }
    void importGraph();
    void exportGraph();
    void drawGraph();

};


#endif //PJC_MANAGER_H
