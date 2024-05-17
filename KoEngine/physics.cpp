#include "physics.h"
#include "player.h"

void updatePhysics(Player& player, float deltaTime, float bounceDamping) {
    player.xSpeed += player.xAcceleration * deltaTime;
    player.ySpeed += player.yAcceleration * deltaTime;
    player.angularSpeed += player.angularAcceleration * deltaTime; // ���������� ������� ��������

    player.xOffset += player.xSpeed * deltaTime;
    player.yOffset += player.ySpeed * deltaTime;
    player.rotation += player.angularSpeed * deltaTime; // ���������� �������� ��������

    // ���������� ������� ��������, ����� ����� �����������
    player.xSpeed *= 0.99f;
    player.ySpeed *= 0.99f;
    player.angularSpeed *= 0.99f; // ������� ������� ��������
}
