#include "HighCard.hpp"
#include <algorithm>

/**
 * @brief Menghitung nilai Straight dengan skema sebagai berikut
 * AAAABBCCCCDDEEEEFFGGGGHHIIIIJJKKKKLLMMMMNN (Dalam basis 2)
 * A: Kartu tertinggi ke-1
 * B: Tipe kartu tertinggi ke-1
 * C: Kartu tertinggi ke-2
 * D: Tipe kartu tertinggi ke-2
 * E: Kartu tertinggi ke-3
 * F: Tipe kartu tertinggi ke-3
 * G: Kartu tertinggi ke-4
 * H: Tipe kartu tertinggi ke-4
 * I: Kartu tertinggi ke-5
 * J: Tipe kartu tertinggi ke-5
 * K: Kartu tertinggi ke-6 
 * L: Tipe kartu tertinggi ke-6 
 * M: Kartu tertinggi ke-7 
 * N: Tipe kartu tertinggi ke-7
 * 
 * @param cards Kartu yang dimiliki player digabung dengan kartu di table (PlayerDeck + TableDeck)
 */
HighCard::HighCard(const vector<CardCandy> &cards) : Comboable(1) {
    computeCombo(cards);
}

void HighCard::computeCombo(vector<CardCandy> cards) {
    sort(cards.begin(), cards.end(), [](CardCandy a, CardCandy b)
        { return ((a > b)); });
    for (int i = 0; i <= 6; i++) {
        const CardCandy &card = cards[i];
        this->comboValue = (this->comboValue<<4) + card.getNumber();
        this->comboValue = (this->comboValue<<2) + card.getType();
    }
}