#include "string.hpp"
#include <algorithm>

void lower(string &s)
{
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c)
                 { return std::tolower(c); });
}