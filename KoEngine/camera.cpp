#include "camera.h"
#include "player.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position)
    : Position(position), Front(glm::vec3(0.0f, 0.0f, -1.0f)), Up(glm::vec3(0.0f, 1.0f, 0.0f)),
    DistanceFromPlayer(5.0f), AngleAroundPlayer(0.0f), Yaw(-90.0f), Pitch(0.0f),
    MovementSpeed(2.5f), MouseSensitivity(0.1f), Zoom(45.0f) {}

void Camera::update(const Player& player) {
    glm::vec3 playerPos(player.xOffset, player.yOffset, player.zOffset);
    float horizontalDistance = DistanceFromPlayer * cos(glm::radians(Pitch));
    float verticalDistance = DistanceFromPlayer * sin(glm::radians(Pitch));
    Position.x = playerPos.x + horizontalDistance * sin(glm::radians(AngleAroundPlayer));
    Position.y = playerPos.y + verticalDistance;
    Position.z = playerPos.z + horizontalDistance * cos(glm::radians(AngleAroundPlayer));

    // Обновите матрицу вида или другие параметры камеры здесь, если нужно
}
