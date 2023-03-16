#include "./candy/candy.hpp"
#include "./cangkul/cangkul.cpp"
#include "./utils/interface.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const string ascii = "\n _______  _______  ___      _______  __   __  _______  _______ \n|       ||       ||   |    |   _   ||  |_|  ||   _   ||       |\n|  _____||    ___||   |    |  |_|  ||       ||  |_|  ||_     _|\n| |_____ |   |___ |   |    |       ||       ||       |  |   |  \n|_____  ||    ___||   |___ |       ||       ||       |  |   |  \n _____| ||   |___ |       ||   _   || ||_|| ||   _   |  |   |  \n|_______||_______||_______||__| |__||_|   |_||__| |__|  |___|  \n ______   _______  _______  _______  __    _  _______          \n|      | |   _   ||       ||   _   ||  |  | ||       |         \n|  _    ||  |_|  ||_     _||  |_|  ||   |_| ||    ___|         \n| | |   ||       |  |   |  |       ||       ||   | __          \n| |_|   ||       |  |   |  |       ||  _    ||   ||  |         \n|       ||   _   |  |   |  |   _   || | |   ||   |_| |         \n|______| |__| |__|  |___|  |__| |__||_|  |__||_______|         \n";

int main()
{
    clearTerminal();
    string out;
    cout << cyellow() << ascii << reset() << endl;
    cout << cgreen() << "+-----------------+\n|    MAIN MENU    |\n+-----------------+" << endl;
    cout << "|1." << cpink() << " Candy Land" << cgreen() << "    |" << endl;
    cout << "|2." << cblue() << " Cangkul" << cgreen() << "       |" << endl;
    cout << "|3. " << cred() << "Exit" << cgreen() << "          |" << endl
         << "+-----------------+" << reset() << endl;
    cout << "Masukkan pilihan: [1/2/3]\n> ";

    cin >> out;
    if (out == "1")
    {
        clearTerminal();
        Candy::start();
    }
    else if (out == "2")
    {
        clearTerminal();
        Cangkul::start();
    }
    // gausah diloop di sini

    cout << cred() << "dadah :)" << reset() << endl;

    return 0;
}