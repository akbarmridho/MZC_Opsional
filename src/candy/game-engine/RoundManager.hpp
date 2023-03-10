#ifndef ROUNDMANAGER_HPP
#define ROUNDMANAGER_HPP

#include <iostream>
#include "../player/PlayerCandy.hpp"

class RoundManager
{
private:
    int currentPlayerIdx;
    int roundCountRM;
    PlayerCandy *players[7];

public:
    RoundManager();
    RoundManager(PlayerCandy *[]);
    PlayerCandy *getCurrentPlayer();
    /**
     * Ubah ke player selanjutnya.
     *
     * Mengembalikan false jika giliran pemain
     * sudah semua
     */
    bool nextPlayer();
    /**
     * Dipanggil ketika giliran sudah habis.
     * Akan mengacak kembali urutan pemain (pindahkan player pertama sebelumnya ke terakhir)
     */
    bool nextRound();

    void reversePlayer();
};

#endif