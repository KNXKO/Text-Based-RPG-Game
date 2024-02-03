#ifndef GAME_HPP
#define GAME_HPP

#include <time.h>
#include "ConsoleColor.h"

#include "warrior.hpp"
#include "mage.hpp"
#include "rogue.hpp"
#include "playerinfo.hpp"

using namespace std;

class Game
{
private:
    int first()
    {
        return rand() % 6 + 1;
    }
public:
    // NAME / HEALTH / MAXHEALTH / STAMINA / MAXSTAMINA / ARMOR / INTELLIGENCE / LUCK / XP
    Warrior* player1 = new Warrior("Matovic",20,20,15,15,5,3,3,0);
    Player* player = player1;

    Mage* mage1 = new Mage("Gandalf",15,15,10,10,0,4,2,10);
    Player* mage = mage1;

    Rogue* rogue1 = new Rogue("Jozef",15,18,15,15,3,1,5,20);
    Player* rogue = rogue1;

    Mage* mage2 = new Mage(*mage1,"Fico");
    Player* mage_other = mage2;

    Game() {}
    ~Game() {}
    void winner()
    {
        cout << endl;
        cout << "                                                                      " << endl;
        cout << "@@@  @@@ @@@ @@@ @@@  @@@ @@@@@@@   @@@@@@  @@@             @@@@@@ @@@" << endl;
        cout << "@@!  @@@ @@! !@@ @@!  @@@ @@!  @@@ @@!  @@@ @@!            !@@     @@!" << endl;
        cout << "@!@  !@!  !@!@!  @!@!@!@! @!@!!@!  @!@!@!@! @!!             !@@!!  !!@" << endl;
        cout << " !: .:!    !!:   !!:  !!! !!: :!!  !!:  !!! !!:                !:! !!:" << endl;
        cout << "   ::      .:     :   : :  :   : :  :   : : : ::.: :       ::.: :  :  " << endl;
        cout << "                                                                      " << endl;
        cout << endl;
    }
    void lvl1()
    {
        cout << endl;
        cout << "                                     " << endl;
        cout << "@@@      @@@  @@@ @@@             @@@" << endl;
        cout << "@@!      @@!  @@@ @@!            @@@@" << endl;
        cout << "@!!      @!@  !@! @!!             !@!" << endl;
        cout << "!!:       !: .:!  !!:             !!!" << endl;
        cout << ": ::.: :    ::    : ::.: :        :: " << endl;
        cout << "                                     " << endl;
        cout << endl;
    }
    void lvl2()
    {
        cout << endl;
        cout << "                                      " << endl;
        cout << "@@@      @@@  @@@ @@@          @@@@@@ " << endl;
        cout << "@@!      @@!  @@@ @@!         @@   @@@" << endl;
        cout << "@!!      @!@  !@! @!!           .!!@! " << endl;
        cout << "!!:       !: .:!  !!:          !!:    " << endl;
        cout << ": ::.: :    ::    : ::.: :    :.:: :::" << endl;
        cout << "                                      " << endl;
        cout << endl;
    }
    void lvl3()
    {
        cout << endl;
        cout << "                                     " << endl;
        cout << "@@@      @@@  @@@ @@@         @@@@@@ " << endl;
        cout << "@@!      @@!  @@@ @@!             @@!" << endl;
        cout << "@!!      @!@  !@! @!!          @!!!: " << endl;
        cout << "!!:       !: .:!  !!:             !!:" << endl;
        cout << ": ::.: :    ::    : ::.: :    ::: :: " << endl;
        cout << "                                     " << endl;
        cout << endl;
    }
    void free()
    {
        delete(player);
        delete(mage);
        delete(rogue);
    }
    // Hracie platno. Herny cyklus
    void run()
    {
        int playerStart;
        int mageStart;
        int rogueStart;
        int mage_otherStart;
        srand(time(NULL));
        lvl1(); // Vypis LVL 1
        // Hod kockou
        playerStart = first();
        mageStart = first();
        // Vypis statov
        player->printStats();
        mage->printStats();
        Sleep(2000);
        // Hraci cyklus
        while (player->getHealth() > 0 && mage->getHealth() > 0)
        {
            //  Kto hodi kockou vacsie cislo zacina
            if (playerStart > mageStart)
            {
                player->move(*mage);
                if (mage->getHealth() > 0)
                {
                    Sleep(1000);
                    mage->move(*player);
                }
                Sleep(1000);
            }
            else
            {
                mage->move(*player);
                if (player->getHealth() > 0)
                {
                    Sleep(1000);
                    player->move(*mage);
                }
                Sleep(1000);
            }
        }
        if (player->getHealth() <= 0)
        {
            cout << "Prehral si :(" << endl;
            return;
        }
        else
        {
            cout << "Zabil si maga " << mage->getName() << endl << endl;
            player->setXP(mage->getXP());
        }
        player->restoreHP(); // Hracovi sa doplni HP do MAX
        player->restoreST(); // Hracovi sa doplni STAMINA do MAX
        lvl2(); // Vypis LVL 2
        getchar();
        // Hod Kockou
        playerStart = first();
        rogueStart = first();
        // Vypis statov
        player->printStats();
        rogue->printStats();
        Sleep(2000);
        // Hraci cyklus
        while (player->getHealth() > 0 && rogue->getHealth() > 0)
        {
            if (playerStart > rogueStart) //  Kto hodi kockou vacsie cislo zacina
            {
                player->move(*rogue);
                if (rogue->getHealth() > 0)
                {
                    Sleep(1000);
                    rogue->move(*player);
                }
                Sleep(1000);
            }
            else
            {
                rogue->move(*player);
                if (player->getHealth() > 0)
                {
                    Sleep(1000);
                    player->move(*rogue);
                }
                Sleep(1000);
            }
        }
        if (player->getHealth() <= 0)
        {
            cout << "Prehral si :(" << endl;
            return;
        }
        else
        {
            cout << "Zabil si lovca " << rogue->getName() << endl << endl;
            player->setXP(rogue->getXP());
        }

        player->restoreHP(); // Hracovi sa doplni HP do MAX
        player->restoreST(); // Hracovi sa doplni STAMINA do MAX
        lvl3(); // Vypis LVL 3
        getchar();
        // Hod Kockou
        playerStart = first();
        mage_otherStart = first();
        // Vypis statov
        player->printStats();
        mage_other->printStats();
        Sleep(2000);
        // Hraci cyklus
        while (player->getHealth() > 0 && mage_other->getHealth() > 0)
        {
            //  Kto hodi kockou vacsie cislo zacina
            if (playerStart > mage_otherStart)
            {
                player->move(*mage_other);
                if (mage_other->getHealth() > 0)
                {
                    Sleep(1000);
                    mage_other->move(*player);
                }
                Sleep(1000);
            }
            else
            {
                mage_other->move(*player);
                if (player->getHealth() > 0)
                {
                    Sleep(1000);
                    player->move(*mage_other);
                }
            }
            Sleep(1000);
        }

        if (player->getHealth() <= 0)
        {
            cout << "Prehral si :(" << endl;
            return;
        }
        else
        {
            cout << "Zabil si maga " << mage_other->getName() << endl << endl;
            player->setXP(mage_other->getXP());
            winner(); // Vypis - vyhral si
        }

    }
};

#endif
