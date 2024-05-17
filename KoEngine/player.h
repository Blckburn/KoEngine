#ifndef PLAYER_H
#define PLAYER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"

class Player
{
public:
    Player();
    void render(Shader& shader);

private:
    unsigned int VAO, VBO, EBO;
    float xOffset, yOffset, zOffset;
    float xSpeed, ySpeed, zSpeed;

    float vertices[20] = {
        // позиции         // текстурные координаты
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // верхний правый угол
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // нижний правый угол
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // нижний левый угол
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // верхний левый угол
    };

    unsigned int indices[6] = {
        0, 1, 3,
        1, 2, 3
    };
};

#endif
