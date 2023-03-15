#include "CangkulDeckManager.hpp"
#include <iostream>
#include "../../base/exception/DeckException.hpp"
#include "../../utils/debug.hpp"
#include "../../utils/interface.hpp"
using std::cin;
using std::cout;
using std::endl;

CangkulDeckManager::CangkulDeckManager() = default;

CangkulDeckManager::CangkulDeckManager(PlayerCangkul *players[4])
{
  for (int i = 0; i < 4; i++)
  {
    this->players[i] = players[i];
  }
}

void CangkulDeckManager::resetDeck()
{
  string choice;
  bool valid = false;

  while (!valid)
  {
    cout << "Apakah anda ingin mengacak atau mengambil urutan kartu dari file? [acak/file]" << endl;
    cout << "> ";
    cin >> choice;

    if (choice == "acak")
    {
      gameDeck.shuffle();
      valid = true;
    }
    else if (choice == "file")
    {
      cout << "Masukkan nama file: " << endl;
      cout << "> ";
      string path;
      cin >> path;

      try
      {
        gameDeck.fromFile(path);
        valid = true;
      }
      catch (DeckException &e)
      {
        cout << "Pembacaan file gagal" << endl;
        cout << e.what() << endl;
      }
    }
    else
    {
      cout << "Pilihan salah" << endl;
    }
  }
  this->tableDeck.clearWaste();
  this->tableDeck.reset();

  for (int j = 0; j < 4; j++)
  {
    this->players[j]->deck.reset();
    for (int i = 0; i < 7; i++)
    {
      this->players[j]->receiveCard(this->gameDeck.popCard());
    }
  }
}

bool CangkulDeckManager::isTableDeckEmpty() const
{
  return this->tableDeck.getCount() == 0;
}
bool CangkulDeckManager::isGameDeckEmpty() const
{
  return this->gameDeck.getCount() == 0;
}

bool CangkulDeckManager::isWasteEmpty() const
{
  return this->tableDeck.getWasteCount() == 0;
}

bool CangkulDeckManager::getFromPlayer(PlayerCangkul *player)
{
  if (isTableDeckEmpty())
  {
    CardCangkul card = player->selectCard();
    this->tableDeck.insertCard({player, card});
    return true;
  }
  else
  {
    this->tableDeck.printTable();
    CardCangkulType type = this->tableDeck.getCurrentType();
    string captions[] = {
        "Cangkul..",
        "Cangkul..",
        "Cangkul yang dalam..",
        "Menanam jagung..",
        "Di kebun kita.."};

    int captIdx = 0;
#ifndef AUTO_CANGKUL
    if (player->countCardWithType(type) == 0)
    {
      cout << "Anda tidak memiliki kartu dengan tipe " << type << ".\n";
      cout << "Anda harus menyangkul hingga mendapatkan kartu dengan tipe tersebut\n";
      cout << "Tekan enter untuk menyangkul\n";
    }
#endif

    while (player->countCardWithType(type) == 0 &&
           (!isGameDeckEmpty() || !isWasteEmpty()))
    {
      if (isGameDeckEmpty())
      {
        auto waste = this->tableDeck.getWaste();
        this->gameDeck.shuffle(waste);
        this->tableDeck.clearWaste();
      }
#ifndef AUTO_CANGKUL
      string temp;
      getline(cin, temp);
      cout << cyellow() << captions[captIdx % 5] << reset() << endl;
      captIdx++;
#endif
      CardCangkul card = this->gameDeck.popCard();
      cout << "Anda menyangkul kartu dan mendapatkan " << card
           << endl;
      player->receiveCard(card);
      if (card.getType() == type)
      {
        cout << "Selamat! Anda berhasil mendapatkan kartu dengan tipe " << card.getType() << "!\n";
      }
    }

    if (isGameDeckEmpty() && player->countCardWithType(type) == 0)
    {
      cout << "Kartu pada deck telah habis. Pemain otomatis kalah" << endl;
      return false;
    }
    else
    {
      CardCangkul card = player->selectCardWithType(type);
      this->tableDeck.insertCard({player, card});
      return true;
    }
  }
}

vector<PlayerCangkul *> CangkulDeckManager::resolveTableCards()
{
  return this->tableDeck.resolveCards();
}