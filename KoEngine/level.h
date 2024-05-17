#pragma once

#include <vector>
#include "shader.h"

class Level {
public:
    Level();
    void render(const Shader& shader) const;

private:
    unsigned int VAO, VBO;
    void setupLevel();
    void drawFloor(const Shader& shader) const;
};

