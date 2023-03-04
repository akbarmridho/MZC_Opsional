#include "max.hpp"

template <class T>
T &max(T arr[])
{
  int length = sizeof(arr) / sizeof(T);
  if (length == 0)
    throw NoMaxException();
  T *maxEl = arr;
  for (int i = 1; i < length; i++)
  {
    if (arr[i] > *maxEl)
      maxEl = arr + i;
  }
  return *maxEl;
}

template <class T>
T &max(T *arr[])
{
  int length = sizeof(arr) / sizeof(T *);
  if (length == 0)
    throw NoMaxException();
  T *maxEl = arr[0];
  for (int i = 1; i < length; i++)
  {
    if (*arr[i] > *maxEl)
      maxEl = arr[i];
  }
  return *maxEl;
}

pair<string, long> max(map<string, long> obj)
{
  if (obj.size() == 0)
    throw NoMaxException();
  auto it = obj.begin();
  auto maxEl = it;
  while (it != obj.end())
  {
    if (it->second > maxEl->second)
    {
      maxEl = it;
    }
    it++;
  }
  return *maxEl;
}
