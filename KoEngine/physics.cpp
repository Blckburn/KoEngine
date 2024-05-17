#include "physics.h"
#include "player.h"

void Physics::update(Player& player, float deltaTime) {
    player.xSpeed += player.xAcceleration * deltaTime;
    player.ySpeed += player.yAcceleration * deltaTime;
    player.angularSpeed += player.angularAcceleration * deltaTime;

    player.xPosition += player.xSpeed * deltaTime;
    player.yPosition += player.ySpeed * deltaTime;
    player.rotation += player.angularSpeed * deltaTime;
}
