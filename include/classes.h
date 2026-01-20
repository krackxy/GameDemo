#ifndef FUNNYGAME_CLASSES_H
#define FUNNYGAME_CLASSES_H
#include <string>
#include <cmath>
#include <iostream>

enum class DamageType {Slashing,Bludgeoning,Piercing,Fire,Lightning,None};
enum class DamageVun {Slashing,Bludgeoning,Piercing,Fire,Lightning,None};

class classes {
public:
    classes classSelection();
    int hp;
    int ac;
    int speed;
    bool specialAction;
    int exp;
    int lvl;
    int id;
    classes(int HP, int AC, int SPEED, bool SPECIALACTION, int EXP, int LVL, int ID) {
        hp = HP;
        ac = AC;
        speed = SPEED;
        specialAction = SPECIALACTION;
        exp = EXP;
        lvl = LVL;
        id = ID;
    }
};

class summons {
public:
    static summons summon(int id);
    int hp;
    int id;
    int ac;
    int speed;
    std::string name;
    summons(int HP, int AC, int SPEED, int ID, std::string NAME) {
        hp = HP;
        ac = AC;
        speed = SPEED;
        id = ID;
        name = NAME;
    }
};

#endif //FUNNYGAME_CLASSES_H