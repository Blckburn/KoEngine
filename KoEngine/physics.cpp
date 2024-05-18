#include "physics.h"
#include "player.h"

void Physics::update(Player& player, float deltaTime) {
    // Пример обновления физики игрока
    glm::vec3 velocity = player.getVelocity();
    glm::vec3 acceleration = player.getAcceleration();

    // Обновление позиции игрока
    glm::vec3 newPosition = player.getPosition() + velocity * deltaTime;
    player.setPosition(newPosition);

    // Обновление скорости игрока
    glm::vec3 newVelocity = velocity + acceleration * deltaTime;
    player.setVelocity(newVelocity);
}
