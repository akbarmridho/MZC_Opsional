#include "Flush.hpp"
#include <algorithm>

/**
 * @brief Menghitung nilai Flush dengan skema sebagai berikut
 * "AABBCCDDEEFFGGH"
 * A: Nilai tertinggi ke-1
 * B: Nilai tertinggi ke-2
 * C: Nilai tertinggi ke-3
 * D: Nilai tertinggi ke-4
 * E: Nilai tertinggi ke-5
 * F: Nilai tertinggi ke-6 (Optional, bernilai 00 jika tidak terbentuk flush ke-6)
 * G: Nilai tertinggi ke-7 (Optional, bernilai 00 jika tidak terbentuk flush ke-6)
 * H: Warna tipe dari kartu yang membuat flush
 * 
 * @param cards 
 */
Flush::Flush(const vector<CardCandy> &cards)
    : Comboable(6, 0)
{
    computeCombo(cards);
}

void Flush::computeCombo(vector<CardCandy> cards) // copy so that cards can be sorted freely
{

    // sort by value
    sort(cards.begin(), cards.end(), [](CardCandy &a, CardCandy &b)
         {return a.getNumber() > b.getNumber(); });

    vector<int> countType = vector<int>(4, 0);

    for (int i = 0; i < cards.size(); i++)
    {
        const CardCandy &card = cards[i];
        countType[card.getType()]++;
    }

    int typeGreaterThanFive = -1;
    for (int i = 0; i <= 3; i++)
    {
        if (countType[i] >= 5)
        {
            typeGreaterThanFive = i;
            break;
        } 
    }

    if (typeGreaterThanFive != -1)
    {
        int counter = 0;
        for (int i=0; i <= cards.size(); i++)
        {
            const CardCandy &card = cards[i];
            if (card.getType() == typeGreaterThanFive)
            {
                counter++;    
                this->comboValue = this->comboValue * 100 + card.getNumber();
            }
        }
        while (counter < 7)
        {
            counter++;
            this->comboValue *= 100;
        }
        this->comboValue = this->comboValue * 10 + typeGreaterThanFive;
    }

}