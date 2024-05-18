#ifndef LEVEL_H
#define LEVEL_H

#include <glad/glad.h> // GLAD ������ ���� ������� �� ���� ������ ���������� OpenGL
#include "shader.h"
#include "texture.h"

class Level {
public:
    Level();
    void render(const Shader& shader) const;

private:
    void setupLevel();
    GLuint floorVAO, floorVBO;
    Texture floorTexture;
};

#endif
