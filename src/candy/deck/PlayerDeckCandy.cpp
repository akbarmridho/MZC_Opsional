#include "PlayerDeckCandy.hpp"
#include "../combo/Comboable.hpp"
#include "../combo/TwoPair.hpp"
#include "../exception/DeckCandyException.hpp"
#include <algorithm>
using std::sort;

PlayerDeckCandy::PlayerDeckCandy()
{
  comboComputed = false;
}

PlayerDeckCandy::~PlayerDeckCandy()
{
  while (!combos.empty())
  {
    Comboable *combo = combos.back();
    combos.pop_back();
    delete combo;
  }
}

void PlayerDeckCandy::resetDeck()
{
  reset();
  comboComputed = false;
  while (!combos.empty())
  {
    Comboable *combo = combos.back();
    combos.pop_back();
    delete combo;
  }
}

void PlayerDeckCandy::computeCombos(TableDeckCandy &tableDeck)
{
  // cache computation
  if (comboComputed)
    return;
  // do this for all the combos
  combos.push_back(new TwoPair(*this, tableDeck));

  // sort descending
  sort(combos.begin(), combos.end(), [](Comboable *a, Comboable *b)
       { return (*a) > (*b); });
}

bool PlayerDeckCandy::compare(PlayerDeckCandy &other, function<bool(Comboable &, Comboable &)> func)
{
  if (!comboComputed || !other.comboComputed)
    throw NoComputedCombosException();
  // combos length must be the same
  for (int i = 0; i < combos.size(); i++)
  {
    Comboable *c1 = combos[i];
    Comboable *c2 = other.combos[i];
    if (*c1 == *c2)
      continue;
    return func(*c1, *c2);
  }
}

bool PlayerDeckCandy::operator<(PlayerDeckCandy &other)
{
  return compare(
      other, [](Comboable &a, Comboable &b)
      { return a < b; });
}

bool PlayerDeckCandy::operator>(PlayerDeckCandy &other)
{
  return compare(
      other, [](Comboable &a, Comboable &b)
      { return a > b; });
}
