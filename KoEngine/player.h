#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>

class Player {
public:
    glm::vec3 position;
    float xSpeed, ySpeed, angularSpeed;
    float xAcceleration, yAcceleration, angularAcceleration;
    float rotation;
};

#endif // PLAYER_H
