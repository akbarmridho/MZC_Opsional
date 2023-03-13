#include "interface.hpp"
#include <stdlib.h>
#include <stdio.h>

using std::string;

void clearTerminal()
{
#ifdef __WIN32
  system("cls");
#else
  system("clear");
#endif
}

string cred(bool bold)
{
  if (bold)
    return "\033[1;31m";
  else
    return "\033[0;31m";
}

string cgreen(bool bold)
{
  if (bold)
    return "\033[1;32m";
  else
    return "\033[0;32m";
}

string cyellow(bool bold)
{
  if (bold)
    return "\033[1;33m";
  else
    return "\033[0;33m";
}

string cblue(bool bold)
{
  if (bold)
    return "\033[1;34m";
  else
    return "\033[0;34m";
}

string rgb(int r, int g, int b)
{
  char res[26];
  sprintf(res, "\033[38;2;%d;%d;%dm", r, g, b);
  return res;
}

string reset()
{
  return "\033[0m";
}