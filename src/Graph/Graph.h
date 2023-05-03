//
// Created by Gerdzio21 on 2023-03-27.
//

#ifndef PJC_GRAPH_H
#define PJC_GRAPH_H

#include <string>
#include <list>
#include <map>
#include <vector>
namespace graph {
    enum Algorithms {
        DIJKSTRA = 0
    };

    struct ShortestPath {
        std::list<std::string> shortestPath;
        unsigned int shortestPathCost;
    };
    class Graph {
        //std::map<std::string,std::vector<Connection >> vertices;
        std::vector<std::string> importantVertices;
        ShortestPath shortestPathThroughImportantVertices;
        //public: void addVertex(const std::string& vertexName, std::vector<Connection>& conections) {
        //    vertices[vertexName] = conections;
        //}
        public: void addImportantVertex(std::string& vertexName) {
            importantVertices.push_back(vertexName);
        }
        public: std::list<std::string>getShortestPath(Algorithms pathAlgorithm);
        //private: bool isVertexExsist(std::string name) {
        //    return vertices.find(name) != vertices.end();
        //}
    };

} // graph

#endif //PJC_GRAPH_H
