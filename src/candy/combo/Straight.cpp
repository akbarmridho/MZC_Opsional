#include "Straight.hpp"
#include <iostream>
#include <algorithm>

using std::make_pair;
using std::cout;
using std::endl;

/**
 * @brief Menghitung nilai Straight dengan skema sebagai berikut
 * AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLLMMMMNNNN (Dalam basis 2)
 * A: Nilai tertinggi ke-1
 * B: Semua tipe kartu dengan nilai tertinggi ke-1
 * C: Nilai tertinggi ke-2
 * D: Semua tipe kartu dengan nilai tertinggi ke-2
 * E: Nilai tertinggi ke-3
 * F: Semua tipe kartu dengan nilai tertinggi ke-3
 * G: Nilai tertinggi ke-4
 * H: Semua tipe kartu dengan nilai tertinggi ke-4
 * I: Nilai tertinggi ke-5
 * J: Semua tipe kartu dengan nilai tertinggi ke-5
 * K: Nilai tertinggi ke-6 (Optional, bernilai 0000 jika tidak ada kartu Straight ke-6)
 * L: Semua tipe kartu dengan nilai tertinggi ke-6 (Optional, bernilai 0000 jika tidak ada kartu Straight ke-6)
 * M: Nilai tertinggi ke-7 (Optional, bernilai 0000 jika tidak ada kartu Straight ke-7)
 * N: Semua tipe kartu dengan nilai tertinggi ke-7 (Optional, bernilai 0000 jika tidak ada kartu Straight ke-7)
 * 
 * @param cards Kartu yang dimiliki player digabung dengan kartu di table (PlayerDeck + TableDeck)
 */
Straight::Straight(const vector<CardCandy> &cards)
    : Comboable(5, 0)
{
    using VectorPair = vector<pair<int, int>>;
    VectorPair cardBag(13, make_pair(0,0));


    for (const auto card : cards)
    {
        int cardNum = card.getNumber();
        int typeValue = 1<<card.getType();
        cardBag[cardNum - 1].first++;
        cardBag[cardNum - 1].second += typeValue;
    }
    int counter = 0;
    int prevNum = 14;
    for (int i=cardBag.size() - 1; i >= 0; i--)
    {
        const pair<int, int> &card = cardBag[i];
        if (card.first >= 1)
        {
            int currentNum = (i + 1);
            if (currentNum + 1 == prevNum)
            {
                counter++;
                this->comboValue = (this->comboValue<<4) + (currentNum);
                this->comboValue = (this->comboValue<<4) + card.second;
            }
            else
            {
                if (counter >= 5) {break;}
                else
                {
                    counter = 1;
                    this->comboValue = (currentNum);
                    this->comboValue = (this->comboValue<<4) + card.second;
                }
            }
            prevNum = currentNum;
        }
    }
    if (counter >= 5)
    {
        while (counter < 7)
        {
            counter++;
            this->comboValue <<= 8;
        }
    }
    else
    {
        this->comboValue = 0;
    }
}