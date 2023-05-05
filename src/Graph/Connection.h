//
// Created by gerdzio21 on 05.05.2023.
//

#ifndef PJC_CONNECTION_H
#define PJC_CONNECTION_H


#include "Vertex.h"

class Connection {
    Vertex *neighbour;
    unsigned int edgeWeight;
public:
    Connection(Vertex *vertexPtr, unsigned int w) : neighbour(vertexPtr), edgeWeight(w) {}
};


#endif //PJC_CONNECTION_H
