#include "../include/classes.h"
#include "../include/monsters.h"
#include "../include/battles.h"
#include "../include/attacks.h"
level1 lowTierCombat();
summons Summon(int id);

bool operator==(DamageVun lhs, DamageType rhs) {
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}

classes battles::battle(classes player){
    level1 enemyTier1 = lowTierCombat();
    std::cout<<"You have encountered a "<<enemyTier1.name<<"!"<<'\n';
    while(player.hp > 0 && enemyTier1.hp > 0) {
        if (player.speed < enemyTier1.speed) {
            auto atk = attacks::playerAttack(player, enemyTier1);
            if (player.id == 4 && (atk.id == 2 || atk.id == 3 || atk.id == 4)){
                summons shovel = Summon(atk.id);
                if (rand()%20+1+atk.toHit <= enemyTier1.ac) {
                    std::cout<<"You hit!"<<'\n';
                    if (enemyTier1.dmgVun == atk.dmgType) {
                        std::cout<<"You found its weakness! you did "<<atk.dmg*2<<" to it"<<'\n';
                        enemyTier1.hp -= atk.dmg*2;
                    }
                    enemyTier1.hp -= atk.dmg;
                    std::cout<<"You did "<<atk.dmg<<" damage!"<<'\n';
                }
                auto sumatk = attacks::summonAttacks(shovel);
                if (rand()%20+1+sumatk.toHit <= enemyTier1.ac) {
                    std::cout<<"You hit!"<<'\n';
                    if (enemyTier1.dmgVun == sumatk.dmgType) {
                        enemyTier1.hp -= sumatk.dmg*2;
                        std::cout<<"You found its weakness! and did "<<sumatk.dmg*2<<" damage!";
                    }
                    enemyTier1.hp -= sumatk.dmg;
                    std::cout<<"You did "<<sumatk.dmg<<" damage";
                }
            }
            if (rand()%20+1+atk.toHit <= enemyTier1.ac) {
                std::cout<<"You hit!"<<'\n';
                if (enemyTier1.dmgVun == atk.dmgType) {
                    std::cout<<"You found its weakness! you did "<<atk.dmg*2<<" to it"<<'\n';
                    enemyTier1.hp -= atk.dmg*2;
                }
                enemyTier1.hp -= atk.dmg;
                std::cout<<"You did "<<atk.dmg<<" damage!"<<'\n';
            }
        }else {
            auto atk = attacks::playerAttack(player, enemyTier1);
            if (rand()%20+1+atk.toHit < enemyTier1.ac) {
                std::cout<<"You hit!"<<'\n';
                if (enemyTier1.dmgVun == atk.dmgType) {
                    std::cout<<"You found its weakness! and did "<<atk.dmg*2<<" damage!";
                    enemyTier1.hp -= atk.dmg*2;
                }
                enemyTier1.hp -= atk.dmg;
                std::cout<<"You did "<<atk.dmg<<" damage!"<<'\n';
            }
        }
    }
    if (enemyTier1.hp <= 0) {
        player.exp += enemyTier1.exp;
        std::cout<<"you killed "<<enemyTier1.name<<" and earned "<<enemyTier1.exp<<" exp"<<'\n';
        return player;
    }
        std::cout<<"Bob fell in battle :("<<'\n';
        return player;
}
