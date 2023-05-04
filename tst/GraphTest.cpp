//
// Created by gerdzio21 on 02.05.2023.
//

#include "gtest/gtest.h"
#include "../src/Graph/Maze2D.h"
#include "../src/Graph/Graph.h"


TEST( MazeGenerationBeforeGeneration, IDformCooridinatesSameAsID){
    auto* maze2D = new graph::Maze2D(1000,1000,0,0);
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            ASSERT_TRUE(maze2D->getCoordinatesFromId(maze2D->getIdFromCoordinates(x,y)).x ==x);
            ASSERT_TRUE(maze2D->getCoordinatesFromId(maze2D->getIdFromCoordinates(x,y)).y ==y);
        }
    }


}
TEST( MazeGenerationBeforeGeneration, cantGetIdFromNonExsistingCoordinates){
        //TODO
}
TEST( MazeGenerationBeforeGeneration, accessByIDisSameAsAccessByIndex){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    int idx = 0;
    for (int i = 0; i < maze2D->height; i++) {
        for (int j = 0; j < maze2D->width; j++) {
            int id = maze2D->getIdFromCoordinates(j, i);
            ASSERT_TRUE(maze2D->verticesPtrArrayList[idx]->getID() == id);
            idx ++;
        }
    }

}

TEST( MazeGenerationBeforeGeneration, allVerticesSetAsNonVisited){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->visitedVertex[v]==false);
    }
}

TEST( MazeGenerationBeforeGeneration, allConncectionsListAreEmpty){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->vertices[v].empty()==true);
    }
}
TEST( MazeGenerationBeforeGeneration, test){
    auto* maze2D = new graph::Maze2D(3,2,0,0);
    auto* vertex = maze2D->verticesPtrArrayList[0];
    auto* right = maze2D->verticesPtrArrayList[1];
    auto* down = maze2D->verticesPtrArrayList[3];
    maze2D->visitedVertex[right] = true;
    maze2D->visitedVertex[down] = true;
    std::vector<graph::Vertex*> allNeighbours = maze2D->getNotVisitedNeighbours(graph::Maze2D::Coordinates(0,0));
    ASSERT_TRUE(allNeighbours.empty() == true);
    ASSERT_TRUE(vertex == maze2D->verticesPtrArrayList[0]);
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

TEST( MazeGenerationAfterGeneration, allVerticesVisitedAfterGeneration){
    auto* maze2D = new graph::Maze2D(2,2,0,0);
    maze2D->generate();
    for(auto* v : maze2D->verticesPtrArrayList){
        ASSERT_TRUE(maze2D->visitedVertex[v]==true);
    }

}
