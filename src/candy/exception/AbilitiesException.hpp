#ifndef ABILITIESEXCEPTION_HPP
#define ABILITIESEXCEPTION_HPP

#include <exception>
#include <string>

using std::exception;
using std::string;

class UsedCardException : public exception
{
public:
    explicit UsedCardException(string message) : message(std::move(message)) {}
    string what()
    {
        return "Card " + message + " was already used";
    }

private:
    string message;
};

class DeactivatedCardException : public exception
{
public:
    explicit DeactivatedCardException(string message) : message(std::move(message)) {}
    string what()
    {
        return "Card " + message + " was deactivated by another player";
    }

private:
    string message;
};

#endif