#include "physics.h"
#include "player.h"

void updatePhysics(Player& player, float deltaTime, float bounceDamping) {
    player.xSpeed += player.xAcceleration * deltaTime;
    player.ySpeed += player.yAcceleration * deltaTime;
    player.angularSpeed += player.angularAcceleration * deltaTime; // Обновление угловой скорости

    player.xOffset += player.xSpeed * deltaTime;
    player.yOffset += player.ySpeed * deltaTime;
    player.rotation += player.angularSpeed * deltaTime; // Обновление углового поворота

    // Простейший гашение скорости, чтобы игрок остановился
    player.xSpeed *= 0.99f;
    player.ySpeed *= 0.99f;
    player.angularSpeed *= 0.99f; // Гашение угловой скорости
}
