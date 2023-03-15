#ifndef STRING_HPP
#define STRING_HPP

#include <string>
#include <algorithm>
#include <cctype>
#include <locale>

using std::string;

void lower(string &s);

void ltrim(std::string &s);

void rtrim(std::string &s);

void trim(std::string &s);

#endif