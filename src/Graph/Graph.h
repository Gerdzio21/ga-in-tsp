//
// Created by Gerdzio21 on 2023-03-27.
//

#ifndef PJC_GRAPH_H
#define PJC_GRAPH_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include "Vertex.h"
#include "Connection.h"
#include "VertexDoesntExsistException.h"

class Graph {
protected:
    std::map<Vertex *, std::vector<Connection>> vertices;
    std::vector<Vertex *> importantVertices;
    std::vector<Vertex *> verticesPtrArrayList;
public:
    void findPath();

    virtual void draw() = 0;

    virtual void readFromFile(std::string) = 0;

    virtual void saveToFile(std::string path,std::string name) = 0;


    void addImportantVertex(Vertex *vertexPtr) {
        if (std::find(verticesPtrArrayList.begin(), verticesPtrArrayList.end(), vertexPtr) !=
            verticesPtrArrayList.end()) {
            importantVertices.push_back(vertexPtr);
        } else {
            throw VertexDoesntExsistException();
        }
    }

    void removeImportantVertex(Vertex *vertexPtr) {
        auto it = std::find(verticesPtrArrayList.begin(), verticesPtrArrayList.end(), vertexPtr);
        if (it != verticesPtrArrayList.end()) {
            importantVertices.erase(it);
        } else {
            throw VertexDoesntExsistException();
        }
    }
    Vertex* getVertexByName(std::string vertexName){
        for(auto* vertex : verticesPtrArrayList) {
            if(vertex->getName() == vertexName){
                return vertex;
            }else{
                throw VertexDoesntExsistException();
            }
        }
    }
};

#endif //PJC_GRAPH_H
