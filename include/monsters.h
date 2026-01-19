#ifndef FUNNYGAME_MONSTERS_H
#define FUNNYGAME_MONSTERS_H
#include <string>
#include <vector>

class level1 {
public:
    int hp;
    DamageVun dmgVun;
    int ac;
    int exp;
    int speed;
    int amount;
    std::string name;
    std::string condition;
    int id;
    level1(int HP, int AC, int EXP, int SPEED, int AMOUNT, int ID,std::string NAME, DamageVun DMG_VUN, std::string CONDITION) {
        hp = HP;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        amount = AMOUNT;
        name = NAME;
        id = ID;
        dmgVun = DMG_VUN;
        condition = CONDITION;
    }
};

class level2 {
public:
    int hp;;
    DamageVun dmgVun;
    int ac;
    int exp;
    int speed;
    int amount;
    int id;
    std::string name;
    std::string condition;
    level2(int HP, int AC, int EXP, int SPEED, int AMOUNT, int ID,std::string NAME, DamageVun DMG_VUN, std::string CONDITION) {
        hp = HP;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        amount = AMOUNT;
        name = NAME;
        id = ID;
        dmgVun = DMG_VUN;
        condition = CONDITION;
    }
};

class level3 {
public:
    int hp;
    DamageVun dmgVun;
    int dmg;
    int ac;
    int exp;
    int speed;
    int amount;
    int id;
    std::string name;
    std::string condition;
    level3(int HP, int AC, int EXP, int SPEED, int AMOUNT, int ID, std::string NAME, DamageVun DMG_VUN, std::string CONDITION) {
        hp = HP;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        amount = AMOUNT;
        id = ID;
        name = NAME;
        dmgVun = DMG_VUN;
        condition = CONDITION;
    }
};
#endif //FUNNYGAME_MONSTERS_H