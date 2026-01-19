#include "../include/attacks.h"
#include <map>
std::vector<std::string> dmgType = {"Slashing", "Bludgening", "Piercing", "Fire", "Lightning", "Ice", "Darkness", "Light"};
std::vector<std::string> summonType = {"Imp","Wyrm","Little golem", "None"};

attacks  attacks::playerAttack(classes& player, level1& enemyTier1){
    int attack;
    switch (player.id) {
        case 1: {
            //Barbarian
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Axe(Slashing)"<<'\n'<<"[2]Quarterstaff(Bludgenoning)"<<'\n'<<"[3]Spear(Piercing)"<<'\n'<<"[4]Rage(Buffs damage output)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            if (attack == 4) {
                player.specialAction = true;
            }
            int dmg1 = player.specialAction && attack == 1 ? 6:4;
            int dmg2 = player.specialAction && attack == 2 ? 5:3;
            int dmg3 = player.specialAction && attack == 3 ? 4:2;
            std::map<int,attacks> barbarianAttacks = {{1,attacks(DamageType::Slashing, 3,dmg1,1)},{2,attacks(DamageType::Bludgeoning, 3,dmg2,2)},{3,attacks(DamageType::Piercing, 5,dmg3,3)},{4,attacks(DamageType::None, 0,0,4)}};
            return barbarianAttacks.at(attack);
        }
            case 2:{
                //Figter
                std::cout<<"You have the following attacks"<<'\n'<<"[1]Sword(Slashing)"<<'\n'<<"[2]Sword(Piercing)"<<'\n'<<"[3]Pommel strike(Bludgenoning)"<<'\n'<<"[4]Stunning strike(Stun enemy for 1 turn)"<<'\n'<<"Please input the wished action: ";
                std::cin>>attack;
                if (attack == 4) {
                    enemyTier1.condition == true;
                }
                std::map<int,attacks> fighterAttacks = {{1,attacks(DamageType::Slashing, 4,4,1)},{2,attacks(DamageType::Piercing, 5,5,2)},{3,attacks(DamageType::Bludgeoning, 2,3,3)},{4,attacks(DamageType::Slashing, 0,0,4)}};
                return fighterAttacks.at(attack);
            }
        case 3: {
            //Ranger
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Piercing shot(Piercing)"<<'\n'<<"[2]Sharpshot(Piercing)"<<'\n'<<"[3]flaming shot(Fire)"<<'\n'<<"[4]Lightning shot(Lightning)"<<'\n'<<"[5]Sharpshooter(Increases acurracy of the attack"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            if (attack == 4) {
                player.specialAction = true;
            }
            int toHit1 = player.specialAction && attack == 1 ? 6:4;
            int toHit2 = player.specialAction && attack == 2 ? 8:6;
            int toHit3 = player.specialAction && attack == 3 ? 4:2;
            int toHit4 = player.specialAction && attack == 4 ? 6:4;
            std::map<int,attacks> rangerAttacks = {{1,attacks(DamageType::Piercing, toHit1,4,1)},{2,attacks(DamageType::Piercing, toHit2,2,2)},{3,attacks(DamageType::Fire, toHit3,6,3)},{4,attacks(DamageType::Lightning, toHit4,4,4)},{5,attacks(DamageType::Piercing, 0,0,5)}};
            return rangerAttacks.at(attack);
        }
        case 4: {
            //Summoner
            std::cout<<"You have the following attacks"<<'\n'<<"[1]FireBolt(Fire)"<<'\n'<<"[2]Summoning Imp"<<'\n'<<"[3]Summoning Golem"<<'\n'<<"[4]Summoning Aero sprit"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            if (attack == 2 || 3 || 4) {
                player.specialAction = true;
            }
            std::map<int,attacks> summonerAttacks = {{1,attacks(DamageType::Fire, 4,5,1)},{2,attacks(DamageType::Lightning, 0,0,2)},{3,attacks(DamageType::Piercing, 0,0,3)},{4,attacks(DamageType::Piercing, 0,0,4)}};
            return summonerAttacks.at(attack);
        }
        case 5: {
            //Wizard
            std::cout<<"You have the following attacks"<<'\n'<<"[1]FireBolt(fire)"<<'\n'<<"[2]ThunderBolt(lightning)"<<'\n'<<"[3]Knife storm(Slashing)"<<'\n'<<"[4]Flaming whip(Fire)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            std::map<int,attacks> wizardAttacks = {{1,attacks(DamageType::Fire, 4,5,1)},{2,attacks(DamageType::Lightning, 5,6,2)},{3,attacks(DamageType::Slashing, 2,8,3)},{4,attacks(DamageType::Fire, 7,4,4)}};
            return wizardAttacks.at(attack);
        }
    }
}

attacks attacks::summonAttacks(summons& summon) {
    int attack;
    switch (summon.id) {
        case 1: {
            //Imp
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Claws(Slashing)"<<'\n'<<"[2]FireBol(Fire)"<<'\n'<<"[3]Tail Piercer(Piercing)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            std::map<int,attacks> impAttacks = {{1,attacks(DamageType::Slashing, 3,2,1)},{2,attacks(DamageType::Fire, 2,3,2)},{3,attacks(DamageType::Piercing, 4,2,3)}};
            return impAttacks.at(attack);
        }
        case 2: {
            //Golem
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Slam(Bludgeoning)"<<'\n'<<"[2]LightningBolt(Lightning)"<<'\n'<<"[3]Body Slam(Bludgeoning)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            std::map<int,attacks> golemAttacks = {{1,attacks(DamageType::Bludgeoning, 4,2,1)},{2,attacks(DamageType::Lightning,6,3,2)}{3,attacks(DamageType::Bludgeoning,0,6,3)}};
            return golemAttacks.at(attack);
        }
        case 3: {
            //Aero sprit
            std::cout<<"You have the following attacks"<<'\n'<<"[1]Slashing winds(Slashing)"<<'\n'<<"[2]Electric winds(Lighnting)"<<'\n'<<"[3]Thunder storm(Lightning)"<<'\n'<<"Please input the wished action: ";
            std::cin>>attack;
            std::map<int,attacks> aeroSpritAttacks = {{1,attacks(DamageType::Slashing,4,3,1)},{2,attacks(DamageType::Lightning, 2,4,2)},{3,attacks(DamageType::Lightning,0,6,3)}};
            return aeroSpritAttacks.at(attack);
        }
    }
}