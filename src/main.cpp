#include "./candy/candy.hpp"
#include "./cangkul/cangkul.cpp"
#include "./utils/interface.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    clearTerminal();
    string out;

    cout << "MAIN MENU" << endl;
    cout << "1." << cyellow() << " Candy Land" << reset() << endl;
    cout << "2." << cblue() << " Cangkul" << reset() << endl;
    cout << "3. " << cred() << "Exit\n"
         << reset();
    cout << "Masukkan pilihan: [1/2/3]\n> ";

    cin >> out;
    clearTerminal();
    if (out == "1")
    {
        Candy::start();
    }
    else if (out == "2")
    {
        Cangkul::start();
    }
    // gausah diloop di sini

    cout << cred() << "dadah :)" << reset() << endl;

    return 0;
}