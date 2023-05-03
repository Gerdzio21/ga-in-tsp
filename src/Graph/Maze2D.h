//
// Created by gerdzio21 on 02.05.2023.
//

#ifndef PJC_MAZE2D_H
#define PJC_MAZE2D_H


#include <stack>
#include <utility>
#include "Graph.h"

namespace graph {

    class Vertex {
    private:
        const std::string name;
        const int ID;
    public:
        Vertex(std::string n, int id) : name(std::move(n)), ID(id) {}

        int getID() {
            return ID;
        }
    };

    class Connection {
        Vertex *neighbour;
        unsigned int edgeWeight;
    public:
        Connection(Vertex *vertexPtr, unsigned int w) : neighbour(vertexPtr), edgeWeight(w) {}
    };

    class Maze2D {
    public:
        unsigned int width;
        unsigned int height;
        unsigned int markingProb;
        unsigned int breakThroughProb;

        struct Coordinates {
            int x;
            int y;

            Coordinates(int x, int y) : x(x), y(y) {}
        };
        std::map<Vertex *, bool> visitedVertex;
        std::map<Vertex *, std::vector<Connection>> vertices;
        std::vector<Vertex *> importantVertices;
        std::vector<Vertex *> verticesPtrArrayList;
        Maze2D(unsigned int width, unsigned int height, unsigned int markingProb, unsigned int breakThroughProb) {
            this->width = width;
            this->height = height;
            this->markingProb = markingProb;
            this->breakThroughProb = breakThroughProb;
            createVertices();
        }
        void createVertices() {
            createVerticesPtrArrayList();
        }
        void createVerticesPtrArrayList() {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    int id = getIdFromCoordinates(j, i);
                    auto* newVertex = new Vertex(std::to_string(id), id);
                    verticesPtrArrayList.push_back(newVertex);
                    visitedVertex[newVertex] = false;
                }
            }
        }
        virtual void generate() {
            std::stack<Vertex *> stack;
            auto* startingVertex = verticesPtrArrayList[0];
            visitedVertex[startingVertex] = true;
            stack.push(startingVertex);
            while (!stack.empty()) {
                auto *currentVertex = stack.top();
                stack.pop();
                int id = currentVertex->getID();
                Coordinates vertexCoordinates = getCoordinatesFromId(id);
                auto n = vertexCoordinates.x;
                auto m = vertexCoordinates.y;
                chooseAndMarkAsImportant(id);
                std::vector<Vertex *> notVisitedNeighbours = getNotVisitedNeighbours(vertexCoordinates);

                // select unvisited neighbour,
                // delete wall between currentCell and the chosen
                // mark the chosen as visited
                // append chosen to LIFO
                if (!notVisitedNeighbours.empty()) {
                    auto *theChosenOne = getRandomUnvisitedNeighbour(notVisitedNeighbours);
                    visitedVertex[theChosenOne] = true;
                    stack.push(currentVertex);
                    stack.push(theChosenOne);
                    createConnection(currentVertex, theChosenOne);
                }
                /*
                 * CODE TO PASTE
                 */
            }
        }

        Vertex *getRandomUnvisitedNeighbour(
                const std::vector<Vertex *> &notVisitedNeighbours) const {
            return notVisitedNeighbours[(rand() % notVisitedNeighbours.size())];
        }

        void createConnection(Vertex *vertexPtr_A, Vertex *vertexPtr_B) {
            vertices[vertexPtr_A].emplace_back(vertexPtr_B, 1);
            vertices[vertexPtr_B].emplace_back(vertexPtr_A, 1);
        }

        void chooseAndMarkAsImportant(int id) {
            if (rand() / RAND_MAX < markingProb) {
                importantVertices.push_back(verticesPtrArrayList[id]);
            }
        };

        std::vector<Vertex *> getNotVisitedNeighbours(Coordinates vertexCoordinates) {
            std::vector<Vertex *> notVisitedNeighbours;
            addLeftIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
            addRightIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
            addUpperIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
            addLowerIfItIsPossible(notVisitedNeighbours, vertexCoordinates);
            return notVisitedNeighbours;
        }

        void addLeftIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
            if (vertexCoordinates.x != 0) {
                int id = getIdFromCoordinates(vertexCoordinates.x - 1, vertexCoordinates.y);
                addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
            }
        }

        void addRightIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
            if (vertexCoordinates.x != width - 1) {
                int id = getIdFromCoordinates(vertexCoordinates.x + 1, vertexCoordinates.y);
                addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
            }
        }

        void addUpperIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
            if (vertexCoordinates.y != 0) {
                int id = getIdFromCoordinates(vertexCoordinates.x, vertexCoordinates.y - 1);
                addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
            }
        }

        void addLowerIfItIsPossible(std::vector<Vertex *> &notVisitedNeighbours, Coordinates vertexCoordinates) {
            if (vertexCoordinates.y != height - 1) {
                int id = getIdFromCoordinates(vertexCoordinates.x, vertexCoordinates.y + 1);
                addToNotVisitedNeighbours(notVisitedNeighbours, verticesPtrArrayList[id]);
            }
        }

        void addToNotVisitedNeighbours(std::vector<Vertex *> &notVisitedNeighbours, Vertex* vertex) {
            if (!visitedVertex[vertex]) {
                notVisitedNeighbours.push_back(vertex);
            }
        }
        [[nodiscard]] Coordinates getCoordinatesFromId(
                int id) const { //[[nodiscard]], kompilator generuje ostrzeżenie, jeśli wynik funkcji jest ignorowany.
            int y = id % width;
            int x = id - y * width;
            return {x, y};
        }

        [[nodiscard]] int getIdFromCoordinates(int x, int y) const {
            return y * width + x;
        }
    };
}

//CODE TO PASTE
//small improvement - creating breakthtrought
//                if (!notVisitedNeighbours.empty()) {
//                    if (breakThroughProb > rand() / RAND_MAX) {
//                        int x = 0;
//                        int y = -1;
//                        auto direction = rand() % 3;
//                        if (direction == 0) {
//                            int x = -1;
//                            int y = 0;
//                        } else if (direction == 1) {
//                            int x = 1;
//                            int y = 0;
//                        } else if (direction == 2) {
//                            int x = 0;
//                            int y = 1;
//                        }
//                        if (n + x >= 0 && n + x < width && m + y >= 0 && m + y < height) {
//                            auto* selectedVertex = verticesPtrArrayList[getIdFromCoordinates(n+x,m+y)];
//                            createConnection(currentVertex,selectedVertex);
//                        }
//                    }
//                }

#endif //PJC_MAZE2D_H
