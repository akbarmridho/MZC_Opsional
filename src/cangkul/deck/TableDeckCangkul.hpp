#ifndef TABLEDECKCANGKUL_HPP
#define TABLEDECKCANGKUL_HPP

#include "../card/CardCangkul.hpp"
#include "../../base/deck/TableDeck.hpp"

class TableDeckCangkul : virtual public TableDeck<CardCangkul>
{
private:
  CardCangkulType currentType;

public:
  TableDeckCangkul();
  void initCard(CardCangkul &);
  CardCangkulType getCurrentType() const;
};

#endif
