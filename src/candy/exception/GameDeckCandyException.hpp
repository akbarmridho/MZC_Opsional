#ifndef GAMEDECKCANDYEXCEPTIONS_HPP
#define GAMEDECKCANDYEXCEPTIONS_HPP

using std::exception;
using std::string;

class InvalidDeckTypeException: public exception {
public:
    explicit InvalidDeckTypeException(string message) : message(std::move(message)) {}
    string what() {
        return "Invalid deck type on line " + message;
    }
private:
    string message;
};

class InvalidDeckNumberException: public exception {
public:
    explicit InvalidDeckNumberException(string message) : message(std::move(message)) {}
    string what() {
        return "Invalid deck number on line " + message;
    }
private:
    string message;
};

class IncompleteDeckException: public exception {
    string what() {
        return "Deck cards are not complete. Deck should have 52 cards";
    }
};

class DuplicateDeckException: public exception {
public:
    explicit DuplicateDeckException(string message) : message(std::move(message)) {}
    string what() {
        return "Duplicate deck card on line " + message;
    }
private:
    string message;
};

#endif