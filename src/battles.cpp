#include "../include/classes.h"
#include "../include/monsters.h"
#include "../include/battles.h"
#include "../include/attacks.h"

bool operator==(DamageVun lhs, DamageType rhs) {
    return static_cast<int>(lhs) == static_cast<int>(rhs);
}

classes battles::battle(classes player){
    int enemy = rand()%4+1;
    int sumcount = 0;
    auto sum = summons::summon(1);
    level1 enemyTier1 = level1::lowTierCombat(enemy);
    std::vector<level1> enemies = {};
    std::cout<<"You have encountered "<<enemyTier1.amount<<" "<<enemyTier1.name<<"!"<<'\n';
    for (int i = 0; i <= enemyTier1.amount-1; i++){
            level1 enemyTier1 = level1::lowTierCombat(enemy);
            enemies.push_back(enemyTier1);
    }
    while (player.hp >= 0 && enemyTier1.hp >= 0) {
        //********************If you are faster***********************
        if (player.speed < enemyTier1.speed) {
            std::cout<<"There are "<<enemies.size()<<" enemies, which one do you want to attack"<<'\n'<<"Please input a number of what enemy you want to attack: ";
            int attackedEnemy;
            std::cin>>attackedEnemy;
            auto atk = attacks::playerAttack(player,enemyTier1);
            int atkRoll = rand()%20+1+atk.toHit;
            if (atkRoll <= enemies[attackedEnemy-1].ac) {
                std::cout<<"You rolled "<<atkRoll<<" you hit!"<<'\n'<<"You did "<<atk.dmg<<" damage!"<<'\n';
                enemies[attackedEnemy-1].hp -= atk.dmg;
                if (enemies[attackedEnemy-1].hp <= 0) {
                    enemies.erase(enemies.begin()+attackedEnemy-1);
                }
            }
            std::cout<<"You rolled "<<atkRoll<<" you missed"<<'\n';
            if (player.id == 4 && player.specialAction && (!sumcount)) {
                auto sum = summons::summon(atk.id);
                sumcount++;
            }
            if (sumcount == 1) {
                auto sumAtk = attacks::summonAttacks(sum);
                int sumRoll = rand()%20+1+sumAtk.toHit;
                if (sumRoll <= enemies[attackedEnemy].ac) {
                    std::cout<<"You rolled "<<sumRoll<<" you hit!"<<'\n';
                    if (atk.dmgType == enemies[attackedEnemy].dmgVun) {
                        std::cout<<"You hit a weak point! you did "<<sumAtk.dmg*2<<" damage!"<<'\n';
                        enemies[attackedEnemy].hp -= sumAtk.dmg*2;
                    }else {
                        enemies[attackedEnemy].hp -= sumAtk.dmg;
                        std::cout<<"You did "<<sumAtk.dmg<<" damage!"<<'\n';
                        if (enemies[attackedEnemy-1].hp <= 0) {
                            enemies.erase(enemies.begin()+attackedEnemy-1);
                    }

                    }
                }
                std::cout<<"You rolled "<<sumRoll<<" your summon missed"<<'\n';
            }
            for (int i = 0; i <= enemies.size()-1; i++) {
                auto enemyAtk = attacks::enemyAttacks(enemies[i]);
                if (rand()%20+1+enemyAtk.toHit <= player.ac){
                    std::cout<<enemies[i].name<<" hit! you take "<<enemyAtk.dmg<<" damage"<<'\n';
                    player.hp -= enemyAtk.dmg;
                }
                std::cout<<enemies[i].name<<" missed their attack!"<<'\n';
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
