#ifndef DECKCANDYEXCEPTION_HPP
#define DECKCANDYEXCEPTION_HPP

#include <string>
#include <exception>

using std::exception;
using std::string;

class NoComputedCombosException : public exception {
    string what() {
        return "Combo must be computed first";
    }
};

#endif
