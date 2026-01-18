#include "include/battles.h"
#include "include/classes.h"
#include "include/monsters.h"
#include <iostream>

classes classSelection();

int main() {
    srand(time(nullptr));//seeds random so the code always generates random
    classes player = classSelection();
    battles fight;
    classes UpdatedPlayer = fight.battle(player);
    return 0;
}
