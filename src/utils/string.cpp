#include "string.hpp"
#include <algorithm>

void lower(string &s)
{
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c)
                 { return std::tolower(c); });
}

void ltrim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                  { return !std::isspace(ch); }));
}

void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                       { return !std::isspace(ch); })
              .base(),
          s.end());
}

void trim(std::string &s)
{
  rtrim(s);
  ltrim(s);
}