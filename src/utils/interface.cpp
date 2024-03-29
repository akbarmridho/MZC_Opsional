#include "interface.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "debug.hpp"

using std::cin;
using std::cout;
using std::string;
#define ENABLE_COLOR

void clearTerminal()
{
#ifndef DEBUG
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
#endif
}

string cred(bool bold)
{
#ifdef ENABLE_COLOR
  if (bold)
    return "\033[1;31m";
  else
    return "\033[0;31m";
#else
  return "";
#endif
}

string cgreen(bool bold)
{
#ifdef ENABLE_COLOR
  if (bold)
    return "\033[1;32m";
  else
    return "\033[0;32m";
#else
  return "";
#endif
}

string cyellow(bool bold)
{
#ifdef ENABLE_COLOR
  if (bold)
    return "\033[1;33m";
  else
    return rgb(255, 255, 0);
#else
  return "";
#endif
}

string cblue(bool bold)
{
#ifdef ENABLE_COLOR
  if (bold)
    return "\033[1;34m";
  else
    return "\033[0;34m";
#else
  return "";
#endif
}

string cpink()
{
  return rgb(255, 105, 180);
}

string rgb(int r, int g, int b)
{
#ifdef ENABLE_COLOR
  char res[26];
  sprintf(res, "\033[38;2;%d;%d;%dm", r, g, b);
  return res;
#else
  return "";
#endif
}

string reset()
{
  return "\033[0m";
}

int getValidatedInt(string prompt)
{
  while (true)
  {
    cout << prompt;
    int number;
    cin >> number;
    if (!cin.fail())
      return number;
    cout << "Masukan angka tidak valid.\n";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}