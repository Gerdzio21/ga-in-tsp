//
// Created by Gerdzio21 on 2023-03-27.
//

#ifndef PJC_GRAPH_H
#define PJC_GRAPH_H

#include <string>
#include <list>
#include <map>

namespace graph {
    struct Connection{
        std::string neighbourName;
        unsigned int edgeWeight;
    };
    struct ShortestPath{
        std::list<std::string> shortestPath;
        unsigned int shortestPathCost;
    };
    template<typename shortestPathAlgorithmStaticFunction>
    class Graph {
        std::map<std::string,std::list<Connection>> vertices;
        std::list<std::string> importantVertices;
        ShortestPath shortestPathThroughImportantVertices;
        shortestPathAlgorithmStaticFunction shortestPathAlgorithm;

        public: virtual void generate()=0;
        public: virtual void readFromFile(std::string fileName)=0;

        public: void addVertex();
        public: void addImportantVertex();
        public: void removeVertex();
        public: void removeImportantVertex();
        public: bool isVertexExsist(std::string name);
        public: std::list<std::string>getShortestPath();
        private: std::list<std::string> getVerticesConnectedToTheVertex(std::string);
    };

} // graph

#endif //PJC_GRAPH_H
