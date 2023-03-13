#ifndef MAX_HPP
#define MAX_HPP

#include <utility>
#include <string>
#include <map>
#include <exception>

using std::exception;
using std::map;
using std::pair;
using std::string;

class NoMaxException : public exception {
public:
    explicit NoMaxException() {}

    string what() {
        return "No max";
    }
};

template<class T>
T &max(T *arr[], int length);

template<class T>
T &max(T &t1, T &t2);

pair<string, long long> max(map<string, long long> obj);

#endif