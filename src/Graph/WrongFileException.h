//
// Created by gerdzio21 on 08.05.2023.
//

#ifndef PJC_WRONGFILEEXCEPTION_H
#define PJC_WRONGFILEEXCEPTION_H


#include <exception>

class WrongFileException : public std::exception {
const char * what() const throw() {
    return "Saving Error - the data was not save";
}
};


#endif //PJC_WRONGFILEEXCEPTION_H
