#pragma once
#include <glm/glm.hpp>
#include "player.h"

class Camera {
public:
    glm::vec3 Position;
    Camera(Player& player);

    void update();
private:
    Player& player;
};
