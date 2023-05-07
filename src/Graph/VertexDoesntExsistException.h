//
// Created by gerdzio21 on 07.05.2023.
//

#ifndef PJC_VERTEXDOESNTEXSISTEXCEPTION_H
#define PJC_VERTEXDOESNTEXSISTEXCEPTION_H


#include <exception>

struct VertexDoesntExsistException : std::exception {
    const char * what() const throw() {
        return "Given pointer not found in VertexPtrArray";
    }
};


#endif //PJC_VERTEXDOESNTEXSISTEXCEPTION_H
