//
// Created by gerdzio21 on 02.05.2023.
//

#ifndef PJC_MAZE2D_H
#define PJC_MAZE2D_H


#include <stack>
#include <utility>
#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Connection.h"
#include "Coordinates.h"
#include "AccessForbiddenException.h"

class Maze2D : public Graph {
public:
    unsigned int width, height;
    const unsigned int maxIDNumber;

    Maze2D(unsigned int width, unsigned int height) : maxIDNumber(width * height - 1) {
        this->width = width;
        this->height = height;
        createVertices();
    }

    virtual void createVertices() {
        createVerticesPtrArrayList();
    }
    void draw() override;
    virtual void generate() = 0;

    void createVerticesPtrArrayList() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                int id = getIdFromCoordinates(j, i);
                auto *newVertex = new Vertex(std::to_string(id), id);
                verticesPtrArrayList.push_back(newVertex);
            }
        }
    }

    [[nodiscard]] Coordinates getCoordinatesFromId(int id) const {
        int y = id / width;
        int x = id % width;
        return {x, y};
    }

    [[nodiscard]] int getIdFromCoordinates(int x, int y) const {
        int id = y * width + x;
        if (id > maxIDNumber || id < 0)
            throw AccessForbiddenException();
        else return id;
    }
};

#endif //PJC_MAZE2D_H
