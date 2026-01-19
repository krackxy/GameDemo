#ifndef FUNNYGAME_ATTACKS_H
#define FUNNYGAME_ATTACKS_H
#include <string>
#include <vector>
#include "classes.h"
#include "monsters.h"



class attacks {
public:
    static attacks playerAttack(classes& player, level1& enemyTier1);
    static attacks summonAttacks(summons& summon);
    static attacks enemyAttacks(level1& enemyTier1);
    DamageType dmgType;
    int toHit;
    int dmg;
    int id;
    attacks(DamageType DMGTYPE, int TOHIT, int DMG, int ID){
        dmgType = DMGTYPE;
        toHit = TOHIT;
        dmg = DMG;
        id = ID;
    }

};



#endif //FUNNYGAME_ATTACKS_H