//
// Created by gerdzio21 on 05.05.2023.
//

#ifndef PJC_VERTEX_H
#define PJC_VERTEX_H


#include <string>

class Vertex {
private:
    const std::string name;
    const int ID;
public:
    Vertex(std::string n, int id) : name(std::move(n)), ID(id) {}

    [[nodiscard]] int getID() const {
        return ID;
    }
    [[nodiscard]] std::string getName() const {
        return name;
    }
};


#endif //PJC_VERTEX_H
