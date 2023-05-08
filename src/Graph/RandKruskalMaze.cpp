//
// Created by gerdzio21 on 05.05.2023.
//


#include "RandKruskalMaze.h"


void RandKruskalMaze::generate() {
    std::stack<Vertex *> stack;
    auto* startingVertex = verticesPtrArrayList[0];
    visitedVertex[startingVertex] = true;
    stack.push(startingVertex);
    while (!stack.empty()) {
        auto *currentVertex = stack.top();
        stack.pop();
        int id = currentVertex->getID();
        Coordinates vertexCoordinates = getCoordinatesFromId(id);
        chooseAndMarkAsImportant(id);
        std::vector<Vertex *> notVisitedNeighbours = getNotVisitedNeighbours(vertexCoordinates);
        if (!notVisitedNeighbours.empty()) {
            auto *theChosenOne = getRandomUnvisitedNeighbour(notVisitedNeighbours);
            visitedVertex[theChosenOne] = true;
            stack.push(currentVertex);
            stack.push(theChosenOne);
            createConnection(currentVertex, theChosenOne);
        }
        //small improvement - creating breakthrough
        createBreakthrough(currentVertex, vertexCoordinates, notVisitedNeighbours);
    }
}
void RandKruskalMaze::createBreakthrough(Vertex *currentVertex, const Coordinates &vertexCoordinates,
                        const std::vector<Vertex *> &notVisitedNeighbours) {
    int n = vertexCoordinates.x;
    int m = vertexCoordinates.y;
    if (!notVisitedNeighbours.empty()) {
        if (breakThroughProb > rand() / RAND_MAX) {
            int x = 0;
            int y = -1;
            auto direction = rand() % 3;
            if (direction == 0) {
                int x = -1;
                int y = 0;
            } else if (direction == 1) {
                int x = 1;
                int y = 0;
            } else if (direction == 2) {
                int x = 0;
                int y = 1;
            }
            if (n + x >= 0 && n + x < width && m + y >= 0 && m + y < height) {
                auto* selectedVertex = verticesPtrArrayList[getIdFromCoordinates(n + x, m + y)];
                createConnection(currentVertex, selectedVertex);
            }
        }
    }
}




