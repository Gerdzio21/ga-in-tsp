//
// Created by gerdzio21 on 05.05.2023.
//

#ifndef PJC_ACCESSFORBIDDENEXCEPTION_H
#define PJC_ACCESSFORBIDDENEXCEPTION_H


#include <exception>

struct AccessForbiddenException : public std::exception {
    const char * what() const throw() {
        return "Access Forbidden Exception";
    }
};


#endif //PJC_ACCESSFORBIDDENEXCEPTION_H
