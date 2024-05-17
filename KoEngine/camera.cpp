#include "camera.h"
#include "player.h"

Camera::Camera(Player& player) : player(player) {}

void Camera::update() {
    // �������� ������� ������ �� ������ ������� ������
    Position = glm::vec3(player.xPosition, player.yPosition, player.zPosition);
}
