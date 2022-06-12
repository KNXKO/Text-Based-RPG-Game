#ifndef ROGUE_HPP
#define ROGUE_HPP

#include "ConsoleColor.h"
#include "playerinfo.hpp"
#include <time.h>

// 2. Bojovnik MAGE
class Rogue : public Player {
public:
    Rogue(string name, int health, int MaxHealth, int stamina, int MaxStamina, int armor, int intelligence, int luck, int xp) : Player(name,health,MaxHealth,stamina,MaxStamina,armor,intelligence,luck, xp) {}
    ~Rogue() {}
    //Vypis statov
    void printStats() {
        cout << green << "Lovec " << name << " ma vlasnosti:"<< white << endl;
        cout << red  << "Zdravie: "  << health << white << endl;
        cout << red  << "Max zdravie: "  << MaxHealth << white << endl;
        cout << blue << "Stamina: "  << stamina << white << endl;
        cout << blue << "Max Stamina: "  << MaxStamina << white << endl;
        cout << "Brnenie: "  << armor << white << endl;
        cout << "Inteligencia: "  << intelligence << white << endl;
        cout << "Stastie: " << luck << endl << endl;
    }

    //Tah
    void move(Player &p) {
        int roll;
        cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << green << name << " tah: " << white << endl; // Vypis zdravia, staminy a mena
        if(stamina >= 4)
            {
                roll = rollDie(); // Hodenie kocky
                cout << name << " hadze kockou... Skore poskodenia " << roll << endl; // Vypis
                p.wtakeDamage(roll); // Spravenie damagu pouzivatelovi
                stamina -= 4; // Odcitanie staminy
            }
            else
            {
                cout << name << " nema dostatok staminy a dostal krc " << endl << endl; // Vypis
                stamina += rollDie() + 3; // Doplnenie staminy
            }
    }
};

#endif
