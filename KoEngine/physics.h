#ifndef PHYSICS_H
#define PHYSICS_H

#include "game_object.h"
#include "player.h"

class Physics {
public:
    void update(GameObject& object, float deltaTime);
    void update(Player& player, float deltaTime);
};

#endif // PHYSICS_H
