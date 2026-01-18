#include "../include/classes.h"
#include "../include/monsters.h"

classes classSelection() {
    std::cout<<"Welcome to work in progress"<<'\n'<<"Please select your starting class"<<'\n'<<"The following classes are available:"<<'\n'<<"Barbarian[1]"<<'\n'<<"Fighter[2]"<<'\n'<<"Ranger[3]"<<'\n'<<"Summoner[4]"<<'\n'<<"Wizard[5]";
    int x;
    std::cout<<'\n'<<"Please input the number corrosponding to the class you want to play: ";
    std::cin>>x;
    while (true) {
        switch (x) {
            case 1: {
                //Babarian
                std::cout<<"You chose the Barbarian"<<'\n';
                return classes (25,13,8, false,0,1,1);
            }
            case 2: {
                //Figther
                std::cout<<"You chose the Fighter"<<'\n';
                return classes (20,17,6, false,0,1,2);
            }
            case 3: {
                //Ranger
                std::cout<<"You chose the Ranger"<<'\n';
                return classes (15,15,10, false,0,1,3);
            }
            case 4: {
                //Summoner
                std::cout<<"You chose the Summoner"<<'\n';
                return classes (8,10,6, false,0,1,4);
            }
            case 5: {
                //Wizard
                std::cout<<"You chose the Wizard"<<'\n';
                return classes (10,12,2,false,0,1,5);
            }
            default: {
                std::cout<<"Wrong input please try agian"<<'\n';
            }
        }
    }
}

summons Summon(int id) {
    switch (id) {
        case 2: {
            //Imp
            return summons(8,13,7,1, "Imp");
        }
        case 3: {
            //Golem
            return summons(10,16,4,2, "Golem");
        }
        case 4: {
            //Aero sprit
            return summons(5,8,10,3, "Aero sprit");
        }
    }
}

level1 lowTierCombat() {
    level1 goblin(5,2,11,2,8,0,"Goblin",DamageType::Bludgeoning,DamageVun::None, false);
    level1 kobold(6, 3, 12, 2, 8, 0,"Kobold",DamageType::Slashing,DamageVun::None, false);
    level1 bear(12, 6, 8, 8, 6, 0,"Bear",DamageType::Slashing,DamageVun::Fire, false);
    level1 Bandit(8, 4, 14, 4, 4, 0,"Bandit",DamageType::Piercing,DamageVun::None, false);
    int enemy = rand()%4+1;
    switch (enemy) {
        case 1: {
            //Goblin
            int amount = rand()%3+1;
            goblin.amount = amount;
            return goblin;
        }

        case 2: {
            //Kobold
            int amount = rand()%3+1;
            kobold.amount = amount;
            return kobold;
        }
        case 3: {
            //Bear
            int amount = rand()%2+1;
            bear.amount = amount;
            return bear;
        }
        case 4: {
            //Bandit
            int amount = rand()%4+1;
            Bandit.amount = amount;
            return Bandit;
        }
    }
    return goblin;
}