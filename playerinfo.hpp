#ifndef PLAYERINFO_HPP
#define PLAYERINFO_HPP

#include "ConsoleColor.h"

using namespace std;

class Player
{
protected:
    string name;
    int health;
    int MaxHealth;
    int stamina;
    int MaxStamina;
    int armor;
    int intelligence;
    int luck;
    int xp;
    int rollDie()
    {
        return rand() % 6 + 1;
    }
public:
    Player(string name, int health, int MaxHealth, int stamina, int MaxStamina,  int armor, int intelligence, int luck, int xp) : name(name), health(health),MaxHealth(MaxHealth),stamina(stamina),MaxStamina(MaxStamina),armor(armor),intelligence(intelligence), luck(luck), xp(xp) {}
    virtual ~Player() {}

    string getName()
    {
        return this->name;
    }
    int getHealth()
    {
        return this->health;
    }
    int getMaxHealth()
    {
        return this->MaxHealth;
    }
    int getStamina()
    {
        return this->stamina;
    }
    int getMaxStamina()
    {
        return this->MaxStamina;
    }
    int getArmor()
    {
        return this->armor;
    }
    int getIntelligence()
    {
        return this->intelligence;
    }
    int getLuck()
    {
        return this->luck;
    }
    int getXP()
    {
        return this->xp;
    }

    void setXP(int xpecko)
    {
        this->xp = xpecko+this->getXP();
    }

    // Damage pre warriora
    void takeDamage(int damage)
    {
        health -= damage;
        cout << name << " dostal " << damage << " damage a teraz ma " << red << health << white << " HP" << endl << endl;
    }
    // Damage pre mobky
    void wtakeDamage(int d)
    {
        int dodge = rand() % 5 + 1;
        if (dodge == 1)
        {
            cout << name << " sa uhol utoku" << endl << endl;
        }
        else
        {
            health -= d;
            cout << name << " dostal " << d << " damage a teraz ma " << red << health << white << " HP" << endl << endl;
        }
    }
    //Vypis statov
    virtual void printStats() {}
    //Tah
    virtual void move(Player &p) {}
    //Hracovi sa obnovi HP do MAX
    virtual void restoreHP() {}
    //Hracovi sa obnovi STAMINA do MAX
    virtual void restoreST() {}
};

#endif
