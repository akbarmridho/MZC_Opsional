#include "reader.hpp"

#include <fstream>
#include <string>

using std::getline;
using std::ifstream;

vector<string> readLines(const string& path) {
    ifstream infile(path);
    vector<string> result;

    for (string line; getline(infile, line);) {
        result.push_back(line);
    }

    if (infile.is_open()) {
        infile.close();
    }

    return result;
}