#ifndef LEVEL_H
#define LEVEL_H

#include <glm/glm.hpp>
#include "shader.h"
#include "texture.h"

class Level {
public:
    Level(const Texture& texture);
    void render(const Shader& shader) const;
private:
    unsigned int VAO, VBO;
    const Texture& texture;
    void setupLevel();
};

#endif
