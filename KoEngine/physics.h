#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"

void updatePhysics(Player& player, float radius, float bounceDamping);
void handleCollision(Player& player1, Player& player2, float radius);

#endif
