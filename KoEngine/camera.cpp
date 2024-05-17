#include "camera.h"
#include "player.h"

Camera::Camera(Player& player) : player(player) {}

void Camera::update() {
    // »змен€ем позицию камеры на основе позиции игрока
    Position = glm::vec3(player.xPosition, player.yPosition, player.zPosition);
}
