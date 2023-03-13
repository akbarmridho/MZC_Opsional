#include "./candy/candy.hpp"
#include "./cangkul/cangkul.cpp"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    string out;

    cout << "Pilihan game: " << endl;
    cout << "1. Candy Land" << endl;
    cout << "2. Cangkul" << endl;
    cout << "Masukkan pilihan: [1/2]" << endl;

    cin >> out;
    if (out == "1") {
        Candy c;
        c.main();
    } else {
        Cangkul::start();
    }

    return 0;
}