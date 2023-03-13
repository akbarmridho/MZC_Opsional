#include "TableDeckCangkul.hpp"

TableDeckCangkul::TableDeckCangkul()
{
}

void TableDeckCangkul::initCard(CardCangkul &card)
{
  currentType = card.getType();
  insertCard(card);
}