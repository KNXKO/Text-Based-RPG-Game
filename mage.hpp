#ifndef MAGE_HPP
#define MAGE_HPP

#include "ConsoleColor.h"
#include "playerinfo.hpp"

using namespace std;
// 1. Bojovnik MAGE
class Mage : public Player
{

public:
    Mage(string name, int health, int MaxHealth, int stamina, int MaxStamina,  int armor, int intelligence, int luck, int xp) : Player(name,health,MaxHealth,stamina,MaxStamina,armor,intelligence,luck, xp) {}
    ~Mage() {}

    Mage(const Mage& other, std::string name) : Player(name,other.health,other.MaxHealth,other.stamina,other.MaxStamina,other.armor,other.intelligence,other.luck,other.xp) {}

    //Vypis statov
    void printStats()
    {
        cout << green << "Mag " << name << " ma vlasnosti: "<< white << endl;
        cout << red  << "Zdravie: "  << health << white << endl;
        cout << red  << "Max zdravie: "  << MaxHealth << white << endl;
        cout << blue << "Stamina: "  << stamina << white << endl;
        cout << blue << "Max Stamina: "  << MaxStamina << white << endl;
        cout << "Brnenie: " << armor << endl;
        cout << "Inteligencia: " << intelligence << endl;
        cout << "Stastie: " << luck << endl << endl;
    }

    //Tah
    void move(Player &p)
    {
        int roll;
        cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << green << name << " tah: " << white << endl; // Vypis zdravia a mena
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
            stamina += rollDie() + 3; // Hodenie kocky
        }


    }
};

#endif
