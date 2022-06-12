#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "ConsoleColor.h"
#include "playerinfo.hpp"

using namespace std;

// Postava za ktoru hra pouzivatel
class Warrior : public Player
{
public:
    Warrior(string name, int health, int MaxHealth, int stamina, int MaxStamina, int armor, int intelligence, int luck, int xp) : Player(name,health,MaxHealth,stamina,MaxStamina,armor,intelligence,luck,xp) {}
    ~Warrior() {}
    //Vypis statov
    void printStats()
    {
        cout << yellow << "Rytier " << name << " ma vlasnosti: " << white << endl;
        cout << red  << "Zdravie: "  << health << white << endl;
        cout << red  << "Max zdravie: "  << MaxHealth << white << endl;
        cout << blue << "Stamina: "  << stamina << white << endl;
        cout << blue << "Max Stamina: "  << MaxStamina << white << endl;
        cout << "Brnenie: " << armor << endl;
        cout << "Inteligencia: " << intelligence << endl;
        cout << "Stastie: " << luck << endl;
        cout << "XP: " << xp << endl;
        cout << "Uhnutie (dodge): 20% sanza uhnut sa utoku" << endl << endl;
    }
    //Tah
    void move(Player &p)
    {
        int vyber, roll;
        cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << name << " tah: " << endl; // Vypis zdravia a mena
        cout << "(1) Zautocis" << endl;
        cout << "(2) Obnovit zdravie" << endl;
        cout << "(3) Obnovit staminu" << endl;
        cin >> vyber;
        cout << endl;
        if (vyber == 1)
        {
            cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << yellow << name << " tah: " << white << endl; // Vypis zdravia a mena
            if(stamina >= 4)
            {
                roll = rollDie(); // Ulozenie
                cout << name << " hadze kockou... Skore poskodenia " << roll << endl; // Vypis
                p.takeDamage(roll); // Spravenie damagu
                stamina -= 4; // Znizenie staminy
            }
            else
            {
                cout << name << " nema dostatok staminy a dostal krc " << endl << endl; // Vypis
                stamina += 2; // Nadobudnutie staminy
            }

        }
        else if (vyber == 2)
        {
            cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << yellow << name << " tah: " << white << endl; // Vypis zdravia a mena
            cout << "(2) Obnovit zdravie" << endl;
            roll = rollDie(); // Hodenie kocky
            health += roll;
            if (health >= MaxHealth)
            {
                health = MaxHealth;
                cout << name << " dosiahol svoje maximalne zdravie: " << red  << health << white << " HP" << endl << endl;
            }
            else
            {
                cout << "Hodil si kockou: " << roll << endl;
                cout << "Teraz mas: " << red << health << white << " HP" << endl << endl;
            }
        }
        else if (vyber == 3)
        {
            cout << "[" << red << health << white << "][" << blue << stamina << white << "] " << yellow << name << " tah: " << white << endl; // Vypis zdravia, staminy a mena
            cout << "(3) Obnovit staminu" << endl;
            roll = rollDie(); // Hodenie kocky
            stamina += roll + 3;
            if(stamina >= MaxStamina)
            {
                stamina = MaxStamina;
                cout << name << " dosiahol svoju maximalnu staminu: " << blue << stamina << white << endl << endl;
            }
            else
            {
                cout << "Hodil si kockou: " << roll << " + 3" << endl;
                cout << "Teraz mas: " << blue << stamina << white << " Staminy" << endl << endl;
            }

        }

    }
    // Hracovi sa obnovi HP na MAX
    void restoreHP()
    {
        health = MaxHealth;
        cout << "Tvoje zdravie sa obnovilo" << endl;
    }
    // Hracovi sa obnovi stamina na MAX
    void restoreST()
    {
        stamina = MaxStamina;
        cout << "Tvoja stamina sa obnovila" << endl;
    }
};

#endif
