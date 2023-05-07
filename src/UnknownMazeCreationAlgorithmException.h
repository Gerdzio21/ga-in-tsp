//
// Created by gerdzio21 on 07.05.2023.
//

#ifndef PJC_UNKNOWNMAZECREATIONALGORITHMEXCEPTION_H
#define PJC_UNKNOWNMAZECREATIONALGORITHMEXCEPTION_H


#include <exception>

struct UnknownMazeCreationAlgorithmException : public std::exception{
        const char * what() const throw() {
            return "Unknown Maze Creation Algorithm Exception";
        }
};



#endif //PJC_UNKNOWNMAZECREATIONALGORITHMEXCEPTION_H
