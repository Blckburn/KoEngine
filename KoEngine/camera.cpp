#include "camera.h"
#include "player.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position)
    : Position(position), Front(glm::vec3(0.0f, 0.0f, -1.0f)), Up(glm::vec3(0.0f, 1.0f, 0.0f)),
    DistanceFromPlayer(5.0f), AngleAroundPlayer(0.0f) {}

void Camera::update(const Player& player) {
    glm::vec3 playerPos(player.xOffset, player.yOffset, player.zOffset);
    Position = playerPos + glm::vec3(0.0f, 1.0f, DistanceFromPlayer);
    // Обновите матрицу вида или другие параметры камеры здесь, если нужно
}
