#include "physics.h"
#include "player.h"

void Physics::update(Player& player, float deltaTime) {
    // ������ ���������� ������ ������
    glm::vec3 velocity = player.getVelocity();
    glm::vec3 acceleration = player.getAcceleration();

    // ���������� ������� ������
    glm::vec3 newPosition = player.getPosition() + velocity * deltaTime;
    player.setPosition(newPosition);

    // ���������� �������� ������
    glm::vec3 newVelocity = velocity + acceleration * deltaTime;
    player.setVelocity(newVelocity);
}
