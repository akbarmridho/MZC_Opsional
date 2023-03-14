#ifndef DECKEXCEPTIONS_HPP
#define DECKEXCEPTIONS_HPP

#include <string>
#include <exception>

using std::string;

class DeckException {
public:
    virtual string what() = 0;
};

class InvalidDeckTypeException : public DeckException {
public:
    explicit InvalidDeckTypeException(string message) : message(std::move(message)) {}

    string what() {
        return "Invalid deck type on line " + message;
    }

private:
    string message;
};

class InvalidDeckNumberException : public DeckException {
public:
    explicit InvalidDeckNumberException(string message) : message(std::move(message)) {}

    string what() {
        return "Invalid deck number on line " + message;
    }

private:
    string message;
};

class IncompleteDeckException : public DeckException {
    string what() {
        return "Deck cards are not complete. Deck should have 52 cards";
    }
};

class DuplicateDeckException : public DeckException {
public:
    explicit DuplicateDeckException(string message) : message(std::move(message)) {}

    string what() {
        return "Duplicate deck card on line " + message;
    }

private:
    string message;
};

#endif