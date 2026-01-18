#ifndef FUNNYGAME_MONSTERS_H
#define FUNNYGAME_MONSTERS_H
#include <string>
#include <vector>

class level1 {
    level1 lowTierCombat();
public:
    int hp;
    DamageType dmgType;
    DamageVun dmgVun;
    int dmg;
    int ac;
    int exp;
    int speed;
    int amount;
    std::string name;
    bool condition;
    level1(int HP, int DMG, int AC, int EXP, int SPEED, int AMOUNT, std::string NAME, DamageType DMGTYPE, DamageVun DMG_VUN, bool CONDITION) {
        hp = HP;
        dmg = DMG;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        amount = AMOUNT;
        name = NAME;
        dmgType = DMGTYPE;
        dmgVun = DMG_VUN;
        condition = CONDITION;
    }
};

class level2 {
public:
    int hp;
    std::vector<std::string> dmgType;
    std::vector<std::string> dmgVun;
    int dmg;
    int ac;
    int exp;
    int speed;
    level2(int HP, int DMG, int AC, int EXP, int SPEED, const std::vector<std::string>& DMG_VUN) {
        hp = HP;
        dmg = DMG;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        dmgType = {"Slashing", "Bludgening", "Piercing", "Fire", "Lightning", "Ice"};
        dmgVun = DMG_VUN;
    }
};

class level3 {
public:
    int hp;
    std::vector<std::string> dmgType;
    std::vector<std::string> dmgVun = {"Slashing", "Bludgening", "Piercing", "Fire", "Lightning", "Ice", "Darkness", "Light","None"};
    int dmg;
    int ac;
    int exp;
    int speed;
    level3(int HP, int DMG, int AC, int EXP, int SPEED, const std::vector<std::string>& DMG_VUN) {
        hp = HP;
        dmg = DMG;
        ac = AC;
        exp = EXP;
        speed = SPEED;
        dmgType = {"Slashing", "Bludgening", "Piercing", "Fire", "Lightning", "Ice", "Darkness", "Light"};
        dmgVun = DMG_VUN;
    }
};
#endif //FUNNYGAME_MONSTERS_H