#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Player; // Forward declaration

class Camera {
public:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;

    Camera(glm::vec3 position);
    void update(const Player& player); // Обновите это, если нужно

private:
    float DistanceFromPlayer;
    float AngleAroundPlayer;
};

#endif
