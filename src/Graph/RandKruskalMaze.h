//
// Created by gerdzio21 on 05.05.2023.
//

#ifndef PJC_RANDKRUSKALMAZE_H
#define PJC_RANDKRUSKALMAZE_H


#include "KruskalMaze.h"

class RandKruskalMaze : public KruskalMaze{
    unsigned int breakThroughProb;
public:
    RandKruskalMaze(unsigned int width, unsigned int height, unsigned int markingProb, unsigned int breakThroughProb)
            : KruskalMaze(width, height, markingProb) {
        this->breakThroughProb = breakThroughProb;
    }
    void generate() override;
private:
    void createBreakthrough(Vertex *currentVertex, const Coordinates &vertexCoordinates,
                            const std::vector<Vertex *> &notVisitedNeighbours);
};


#endif //PJC_RANDKRUSKALMAZE_H
