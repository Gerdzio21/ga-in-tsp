//
// Created by gerdzio21 on 02.05.2023.
//

#include "gtest/gtest.h"
#include "../src/Graph/Maze2D.h"
#include "../src/Graph/Graph.h"


TEST( MazeGenerationBeforeGeneration, allVerticesSetAsNonVisited){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->visitedVertex[v]==false);
    }
}
TEST( MazeGenerationBeforeGeneration, allNeighboursListAreEmpty){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->vertices[v].empty()==true);
    }
}
TEST( MazeGenerationBeforeGeneration, allNotVisitedNeighboursAreListed){
    auto* maze2D = new graph::Maze2D(3,2,0,0);
    auto* vertex = maze2D->verticesPtrArrayList[0];
    auto* right = maze2D->verticesPtrArrayList[1];
    auto* down = maze2D->verticesPtrArrayList[3];
    std::vector<graph::Vertex*> allNeighbours = maze2D->getNotVisitedNeighbours(graph::Maze2D::Coordinates(0,0));
    ASSERT_TRUE(std::find(allNeighbours.begin(), allNeighbours.end(),right)!=allNeighbours.end());
    ASSERT_TRUE(std::find(allNeighbours.begin(), allNeighbours.end(),down)!=allNeighbours.end());
}
TEST( MazeGeneration, allVerticesVisitedAfterGeneration){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    maze2D->generate();
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->visitedVertex[v]==true);
    }
}