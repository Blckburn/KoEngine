#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "player.h"

class Camera {
public:
    Camera(glm::vec3 position);
    void update(const Player& player);

private:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    float DistanceFromPlayer;
    float AngleAroundPlayer;
    float Yaw;
    float Pitch;
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;
};

#endif // CAMERA_H
