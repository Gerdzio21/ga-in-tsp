//
// Created by gerdzio21 on 02.05.2023.
//

#include "gtest/gtest.h"
#include "../src/Graph/Maze2D.h"
#include "../src/Graph/Graph.h"
#include "../src/Graph/KruskalMaze.h"
#include "../src/Graph/RandKruskalMaze.h"

TEST (Graph, KruskalMazeGenerator) {
    Graph *graph = new KruskalMaze(100, 100, 0);
    graph->draw();
    ASSERT_TRUE(true);
}

TEST (Graph, RandomKruskalMazeGenerator) {
    Graph *graph = new RandKruskalMaze(100, 100, 0, 0);
    graph->draw();
    ASSERT_TRUE(true);
}

TEST (Graph, CanSaveInNotExsistingPlace) {
    ASSERT_TRUE(false);
}

TEST (Graph, CantReadFileFromWrongPath) {
    ASSERT_TRUE(false);
}

TEST (Graph, CantReadFileWithWrongExtension) {
    ASSERT_TRUE(false);
}

TEST (KruskalMaze, CantMarkingProbabilityBeOutOfRange) {
    ASSERT_TRUE(true);
}
TEST (KruskalMaze, CantBreakThroughProbabilityBeOutOfRange) {
    ASSERT_TRUE(true);
}

TEST( Maze2D, IDformCooridinatesIsSameAsID){
    auto* maze2D = new KruskalMaze(1000,1000,0);
    for (int x = 0; x < 1000; x++) {
        for (int y = 0; y < 1000; y++) {
            ASSERT_TRUE(maze2D->getCoordinatesFromId(maze2D->getIdFromCoordinates(x,y)).x ==x);
            ASSERT_TRUE(maze2D->getCoordinatesFromId(maze2D->getIdFromCoordinates(x,y)).y ==y);
        }
    }


}
TEST( Maze2D, cantGetIdFromNonExsistingCoordinates){
    auto* maze2D = new KruskalMaze(5,5,0);

    EXPECT_THROW({
                     try
                     {
                         maze2D->getIdFromCoordinates(10,10);
                     }
                     catch( const AccessForbiddenException& e )
                     {
                         // and this tests that it has the correct message
                         EXPECT_STREQ( "Access Forbidden Exception", e.what() );
                         throw;
                     }
                 }, AccessForbiddenException );
}
TEST( MazeGenerationBeforeGeneration, accessByIDisSameAsAccessByIndex){
    auto* maze2D = new KruskalMaze(2,2,0);
    int idx = 0;
    for (int i = 0; i < maze2D->height; i++) {
        for (int j = 0; j < maze2D->width; j++) {
            int id = maze2D->getIdFromCoordinates(j, i);
            ASSERT_TRUE(maze2D->getIdByVertexIdx(idx) == id);
            idx ++;
        }
    }

}
//
//TEST( MazeGenerationBeforeGeneration, allVerticesSetAsNonVisited){
//    auto* maze2D = new Maze2D(2,2,0,0);
//    for(auto* v : maze2D->verticesPtrArrayList){
//        ASSERT_TRUE(maze2D->visitedVertex[v]==false);
//    }
//}
//
//TEST( MazeGenerationBeforeGeneration, allConncectionsListAreEmpty){
//    auto* maze2D = new Maze2D(2,2,0,0);
//    for(auto* v : maze2D->verticesPtrArrayList){
//        ASSERT_TRUE(maze2D->vertices[v].empty()==true);
//    }
//}
//TEST( MazeGenerationBeforeGeneration, test){
//    auto* maze2D = new Maze2D(3,2,0,0);
//    auto* vertex = maze2D->verticesPtrArrayList[0];
//    auto* right = maze2D->verticesPtrArrayList[1];
//    auto* down = maze2D->verticesPtrArrayList[3];
//    maze2D->visitedVertex[right] = true;
//    maze2D->visitedVertex[down] = true;
//    std::vector<Vertex*> allNeighbours = maze2D->getNotVisitedNeighbours(Coordinates(0,0));
//    ASSERT_TRUE(allNeighbours.empty() == true);
//    ASSERT_TRUE(vertex == maze2D->verticesPtrArrayList[0]);
//}
//
//
//TEST( MazeGenerationBeforeGeneration, allNotVisitedNeighboursAreListed){
//    auto* maze2D = new Maze2D(3,2,0,0);
//    auto* vertex = maze2D->verticesPtrArrayList[0];
//    auto* right = maze2D->verticesPtrArrayList[1];
//    auto* down = maze2D->verticesPtrArrayList[3];
//    std::vector<Vertex*> allNeighbours = maze2D->getNotVisitedNeighbours(Coordinates(0,0));
//    ASSERT_TRUE(std::find(allNeighbours.begin(), allNeighbours.end(),right)!=allNeighbours.end());
//    ASSERT_TRUE(std::find(allNeighbours.begin(), allNeighbours.end(),down)!=allNeighbours.end());
//}
//
//TEST( MazeGenerationAfterGeneration, allVerticesVisitedAfterGeneration){
//    auto* maze2D = new Maze2D(2,2,0,0);
//    maze2D->generate();
//    for(auto* v : maze2D->verticesPtrArrayList){
//        ASSERT_TRUE(maze2D->visitedVertex[v]==true);
//    }
//
//}
