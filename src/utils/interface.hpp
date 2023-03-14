#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "string"
using std::string;

void clearTerminal();

string cred(bool bold = false);

string cgreen(bool bold = false);

string cyellow(bool bold = false);

string cblue(bool bold = false);

string rgb(int r, int g, int b);

string reset();

#endif