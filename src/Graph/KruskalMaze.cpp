//
// Created by gerdzio21 on 05.05.2023.
//

#include <fstream>
#include "KruskalMaze.h"
#include "WrongFileException.h"

void KruskalMaze::generate() {
    std::stack<Vertex *> stack;
    auto *startingVertex = verticesPtrArrayList[0];
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
    }
}

Vertex *KruskalMaze::getRandomUnvisitedNeighbour(
        const std::vector<Vertex *> &notVisitedNeighbours) const {
    return notVisitedNeighbours[(rand() % notVisitedNeighbours.size())];
}

void KruskalMaze::createConnection(Vertex *vertexPtr_A, Vertex *vertexPtr_B) {
    vertices[vertexPtr_A].emplace_back(vertexPtr_B, 1);
    vertices[vertexPtr_B].emplace_back(vertexPtr_A, 1);
}

void KruskalMaze::chooseAndMarkAsImportant(int id) {
    if (rand() / RAND_MAX < markingProb) {
        importantVertices.push_back(verticesPtrArrayList[id]);
    }
};

std::vector<Vertex *> KruskalMaze::getNotVisitedNeighbours(Coordinates vertexCoordinates) {
    std::vector<Vertex *> notVisitedNeighbours;
    addLeftIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
    addRightIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
    addUpperIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
    addLowerIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
    return notVisitedNeighbours;
}

void KruskalMaze::addLeftIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
    if (vertexCoordinates.x - 1 >= 0) {
        int id = getIdFromCoordinates(vertexCoordinates.x - 1, vertexCoordinates.y);
        addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
    }
}

void KruskalMaze::addRightIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
    if (vertexCoordinates.x + 1 < width) {
        int id = getIdFromCoordinates(vertexCoordinates.x + 1, vertexCoordinates.y);
        addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
    }
}

void KruskalMaze::addUpperIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
    if (vertexCoordinates.y - 1 >= 0) {
        int id = getIdFromCoordinates(vertexCoordinates.x, vertexCoordinates.y - 1);
        addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
    }
}

void KruskalMaze::addLowerIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
    if (vertexCoordinates.y + 1 < height) {
        int id = getIdFromCoordinates(vertexCoordinates.x, vertexCoordinates.y + 1);
        addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
    }
}

void KruskalMaze::addToNotVisitedNeighbours(std::vector<Vertex *> &notVisitedNeighbours, Vertex *vertex) {
    if (!visitedVertex[vertex]) {
        notVisitedNeighbours.push_back(vertex);
    }
}

void KruskalMaze::saveToFile(std::string path, std::string fileName) {
    std::fstream file;
    file.open(path + fileName + ".maze", std::ios::out);
    if (file.good()) {
        std::cout << "zapisywanie";
    } else throw WrongFileException();
}

void KruskalMaze::readFromFile(std::string path) {
    //add extension verification
    std::fstream file;
    file.open(path , std::ios::out);
    if (file.good()) {
        std::cout << "odczytywanie";
    } else throw WrongFileException();
}