#ifndef ABILITIESEXCEPTION_HPP
#define ABILITIESEXCEPTION_HPP

#include <exception>
#include <string>

using std::exception;
using std::string;

class AbilityException : public exception
{
public:
    AbilityException(string message) : message(std::move(message)) {}
    virtual string what() = 0;

protected:
    string message;
};

class UsedCardException : public AbilityException
{
public:
    explicit UsedCardException(string message) : AbilityException(message) {}
    string what()
    {
        return "Card " + this->message + " was already used";
    }
};

class DeactivatedCardException : public AbilityException
{
public:
    explicit DeactivatedCardException(string message) : AbilityException(message) {}
    string what()
    {
        return "Card " + this->message + " was deactivated by another player";
    }
};

class NotOwnedCardException : public AbilityException
{
public:
    explicit NotOwnedCardException(string message) : AbilityException(message) {}
    string what()
    {
        return "Card " + this->message + " is not owned by player";
    }
};

#endif