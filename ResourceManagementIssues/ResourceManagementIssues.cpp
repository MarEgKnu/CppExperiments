
#include <iostream>
#include "entity.h"

int main()
{
    entity* enemy = new entity(false, 50);

    entity* player = new entity(true, 70);

    enemy->target = player;

    player->target = enemy;

    player->do_damage(75);

    //delete the enemy to represent it dying

    delete enemy;

    // now the pointer for the target for the player and any other entites will be invalid, and will write into unallocated memory (VERY BAD)

    player->do_damage(30);


}

