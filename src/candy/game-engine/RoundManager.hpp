#ifndef ROUNDMANAGER_HPP
#define ROUNDMANAGER_HPP

#include <deque>
#include <iterator>
#include "../player/PlayerCandy.hpp"

class RoundManager
{
private:
    std::deque<PlayerCandy> players;
    std::deque<PlayerCandy>::iterator currentPlayer;
    int roundCount;

public:
    RoundManager(PlayerCandy [], int*);

    PlayerCandy& getCurrentPlayer();
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
    void nextRound();

    void reversePlayer();
};

#endif