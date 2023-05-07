//
// Created by gerdzio21 on 05.05.2023.
//

#ifndef PJC_KRUSKALMAZE_H
#define PJC_KRUSKALMAZE_H


#include "Maze2D.h"

class KruskalMaze : public Maze2D {
    unsigned int markingProb;
protected:
    std::map<Vertex *, bool> visitedVertex;

    void createConnection(Vertex *vertexPtr_A, Vertex *vertexPtr_B);

    void chooseAndMarkAsImportant(int id);

    std::vector<Vertex *> getNotVisitedNeighbours(Coordinates vertexCoordinates);

    Vertex *getRandomUnvisitedNeighbour(
            const std::vector<Vertex *> &notVisitedNeighbours) const;

public:
    KruskalMaze(unsigned int width, unsigned int height, unsigned int markingProb)
            : Maze2D(width, height) {
        this->markingProb = markingProb;
    }
private:
    void createVertices() override {
        createVerticesPtrArrayList();
        markAllVerticesAsUnvisited();
    }

    void markAllVerticesAsUnvisited() {
        for (auto *vertex: verticesPtrArrayList) { visitedVertex[vertex] = false; }

    }

public:
    void generate() override;

private:

    void addLeftIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates);

    void addRightIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates);

    void addUpperIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates);

    void addLowerIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates);

    void addToNotVisitedNeighbours(std::vector<Vertex *> &notVisitedNeighbours, Vertex *vertex);


};


#endif //PJC_KRUSKALMAZE_H
