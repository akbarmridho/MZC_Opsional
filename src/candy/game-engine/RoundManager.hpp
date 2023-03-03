#ifndef ROUNDMANAGER_HPP
#define ROUNDMANAGER_HPP

#include "../player/PlayerCandy.hpp"

class RoundManager
{

public:
    RoundManager();

    PlayerCandy getCurrentPlayer();
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