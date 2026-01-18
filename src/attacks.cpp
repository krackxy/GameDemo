#include "../include/attacks.h"

std::vector<std::string> dmgType = {"Slashing", "Bludgening", "Piercing", "Fire", "Lightning", "Ice", "Darkness", "Light"};
std::vector<std::string> summonType = {"Imp","Wyrm","Little golem", "None"};

attacks  attacks::playerAttack(classes& player, level1& enemyTier1){
    int attack;
    switch (player.id) {
        case 1: {
            //Barbarian
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Axe(Slashing)"<<'\n'<<"[2]Quarterstaff(Bludgenoning)"<<'\n'<<"[3]Spear(Piercing)"<<'\n'<<"[4]Rage(Buffs damage output)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            switch (attack) {
                case 1: {
                    //Axe slash
                    if (player.specialAction == true) {
                        return attacks(DamageType::Slashing, 3,6,1);
                    }
                    return attacks(DamageType::Slashing, 3,4,1);
                }
                case 2: {
                    //Quarterstaff Bludgenoning
                    if (player.specialAction == true) {
                        return attacks(DamageType::Bludgeoning, 3,5,2);
                    }
                    return attacks(DamageType::Bludgeoning, 3,3,2);
                }
                case 3: {
                    //Spear piercer
                    if (player.specialAction == true) {
                        return attacks(DamageType::Piercing, 5,4,3);
                    }
                    return attacks(DamageType::Piercing, 5,2,3);
                }
                case 4: {
                    //Rage
                    player.specialAction = true;
                    return attacks(DamageType::Bludgeoning, 0,0,4);
                }
            }
        }
            case 2:{
                //Figter
                std::cout<<"You have the following attacks"<<'\n'<<"[1]Sword(Slashing)"<<'\n'<<"[2]Sword(Piercing)"<<'\n'<<"[3]Pommel strike(Bludgenoning)"<<'\n'<<"[4]Stunning strike(Stun enemy for 1 turn)"<<'\n'<<"Please input the wished action: ";
                std::cin>>attack;
                switch (attack) {
                    case 1: {
                        //Sword slash
                        return attacks(DamageType::Slashing, 4,4,1);
                    }
                        case 2: {
                        //Sword thrust
                        return attacks(DamageType::Piercing, 5,5,2);
                    }
                        case 3: {
                        //Pommel strike
                        return attacks(DamageType::Bludgeoning, 2,3,3);
                    }
                        case 4: {
                        //stunning strike
                        enemyTier1.condition = true;
                        return attacks(DamageType::Slashing, 0,0,4);
                    }
                }
            }
        case 3: {
            //Ranger
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Piercing shot(Piercing)"<<'\n'<<"[2]Sharpshot(Piercing)"<<'\n'<<"[3]flaming shot(Fire)"<<'\n'<<"[4]Lightning shot(Lightning)"<<'\n'<<"[5]Sharpshooter(Increases acurracy of the attack"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            switch (attack) {
                case 1: {
                    //Piercing shot
                    if (player.specialAction == true) {
                        return attacks(DamageType::Piercing, 6,4,1);
                    }
                    return attacks(DamageType::Piercing, 4,4,1);
                }
                case 2: {
                    //Sharpshot
                    if (player.specialAction == true) {
                        return attacks(DamageType::Piercing, 8,2,2);
                    }
                    return attacks(DamageType::Piercing, 6,2,2);
                }
                case 3: {
                    //Flaming shot
                    if (player.specialAction == true) {
                        return attacks(DamageType::Fire, 4,6,3);
                    }
                    return attacks(DamageType::Fire, 2,6,3);
                }
                case 4: {
                    //Lightning shot
                    if (player.specialAction == true) {
                        return attacks(DamageType::Lightning, 6,4,4);
                    }
                    return attacks(DamageType::Lightning, 4,4,4);
                }
                case 5: {
                    //Sharpshooter
                    player.specialAction = true;
                    return attacks(DamageType::Piercing, 0,0,5);
                }
            }
        }
        case 4: {
            //Summoner
            std::cout<<"You have the following attacks"<<'\n'<<"[1]FireBolt(Fire)"<<'\n'<<"[2]Summoning Imp"<<'\n'<<"[3]Summoning Golem"<<'\n'<<"[4]Summoning Aero sprit"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            switch (attack) {
                case 1: {
                    //FireBolt
                    return attacks(DamageType::Fire, 4,5,1);
                }
                case 2: {
                    //Imp
                    if (player.specialAction == true) {
                        return attacks(DamageType::Lightning, 0,0,2);
                    }
                    player.specialAction = true;
                    return attacks(DamageType::Lightning, 0,0,2);

                }
                case 3: {
                    //Golem
                    if (player.specialAction == true) {
                        return attacks(DamageType::Piercing, 0,0,3);
                    }
                    player.specialAction = true;
                    return attacks(DamageType::Lightning, 0,0,2);
                }
                case 4: {
                    //Aero sprit
                    if (player.specialAction == true) {
                        return attacks(DamageType::Piercing, 0,0,4);
                    }
                    player.specialAction = true;
                    return attacks(DamageType::Lightning, 0,0,2);
                }
            }
        }
        case 5: {
        //Wizard
        std::cout<<"You have the following attacks"<<'\n'<<"[1]FireBolt(fire)"<<'\n'<<"[2]ThunderBolt(lightning)"<<'\n'<<"[3]Knife storm(Slashing)"<<'\n'<<"[4]Flaming whip(Fire)"<<'\n'<<"Please input the wished action: ";
        std::cin>>attack;
            switch (attack) {
                case 1: {
                    //FireBolt
                    return attacks(DamageType::Fire, 4,5,1);
                }
                    case 2: {
                    //Thunderbolt
                    return attacks(DamageType::Lightning, 5,6,2);
                }
                    case 3: {
                    //Knife storm
                    return attacks(DamageType::Slashing, 2,8,3);
                }
                    case 4: {
                    //Flaming whip
                    return attacks(DamageType::Fire, 7,4,4);
                }
            }
        }
    }
    return attacks(DamageType::Piercing, 3,3,0);
}

attacks attacks::summonAttacks(summons& summon) {
    int attack;
    switch (summon.id) {
        case 1: {
            //Imp
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Claws(Slashing)"<<'\n'<<"[2]FireBol(Fire)"<<'\n'<<"[3]Tail Piercer(Piercing)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            switch (attack) {
                case 1: {
                    //Claws
                    return attacks(DamageType::Slashing, 3,2,1);
                }
                    case 2: {
                    //FireBolt
                    return attacks(DamageType::Fire, 2,3,2);
                }
                    case 3: {
                    //Tail Piercer
                    return attacks(DamageType::Piercing, 4,2,3);
                }
            }
        }
    }
    return attacks(DamageType::Piercing, 0,0,0);
}