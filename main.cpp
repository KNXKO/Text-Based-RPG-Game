#include <iostream>
#include <memory>

#include "game.hpp"

using namespace std;

int main()
{
    int znova;
    do
    {
        cout << "                                                                                                                             " << endl;
        cout << "DDDDDDDDDDDDD      IIIIIIIIII               AAA               BBBBBBBBBBBBBBBBB   LLLLLLLLLLL                  OOOOOOOOO     " << endl;
        cout << "D::::::::::::DDD   I::::::::I              A:::A              B::::::::::::::::B  L:::::::::L                OO:::::::::OO   " << endl;
        cout << "D:::::::::::::::DD I::::::::I             A:::::A             B::::::BBBBBB:::::B L:::::::::L              OO:::::::::::::OO " << endl;
        cout << "DDD:::::DDDDD:::::DII::::::II            A:::::::A            BB:::::B     B:::::BLL:::::::LL             O:::::::OOO:::::::O" << endl;
        cout << "  D:::::D    D:::::D I::::I             A:::::::::A             B::::B     B:::::B  L:::::L               O::::::O   O::::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I            A:::::A:::::A            B::::B     B:::::B  L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I           A:::::A A:::::A           B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I          A:::::A   A:::::A          B:::::::::::::BB    L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I         A:::::A     A:::::A         B::::BBBBBB:::::B   L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I        A:::::AAAAAAAAA:::::A        B::::B     B:::::B  L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D     D:::::DI::::I       A:::::::::::::::::::::A       B::::B     B:::::B  L:::::L               O:::::O     O:::::O" << endl;
        cout << "  D:::::D    D:::::D I::::I      A:::::AAAAAAAAAAAAA:::::A      B::::B     B:::::B  L:::::L         LLLLLLO::::::O   O::::::O" << endl;
        cout << "DDD:::::DDDDD:::::DII::::::II   A:::::A             A:::::A   BB:::::BBBBBB::::::BLL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::O" << endl;
        cout << "D:::::::::::::::DD I::::::::I  A:::::A               A:::::A  B:::::::::::::::::B L::::::::::::::::::::::L OO:::::::::::::OO " << endl;
        cout << "D::::::::::::DDD   I::::::::I A:::::A                 A:::::A B::::::::::::::::B  L::::::::::::::::::::::L   OO:::::::::OO" << endl;
        cout << "DDDDDDDDDDDDD      IIIIIIIIIIAAAAAAA                   AAAAAAABBBBBBBBBBBBBBBBB   LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO  " << endl;
        cout << endl;
        cout << "Vitajte!" << "\nV hre hrajete za postavu warriora, staty mate napisane nizsie. Hra je zlozena z troch levelov v ktorych sa nachadzaju protivnici a vasou ulohou je ich vsetkych zabit! Tah zacina ten kto hodi kockou vacsie cislo. \nV hre mate 3 moznosti co mozte spravit \n(1) Zautocit - zoberiete protivnikovy hp. Kolko zoberiete hp urcuje ake cislo hodite kockou 1-6, zaroven si ale uberiete 4 staminy. Vasa postava ma specialnu abilitu. Mate 20% sancu ze sa vyhnete utokom protivnika. \n(2) Doplnenie HP - na zaklade ake velke cislo hodite kockou sa vam dane cislo pripocita k HP.\n(3) Doplnenie Staminy - doplni sa vam stamina na zaklade toho ake cislo hodite kockou +3.\nProtivnici funguju na tom istom pricipe ako ty." << endl << endl;
        Game game;
        game.run();
        game.free();
        cout << "\n\nChcete hru spustit znova?\n(1) Ano\n(2) Nie\nZadajte 1 alebo 2: " << endl;
        cin >> znova;
    }
    while (znova == 1 || znova < 2);
    cout << "\nDovidenia..." << endl;
    return 0;
}
