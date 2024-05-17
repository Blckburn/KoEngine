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
        // �������         // ���������� ����������
        0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // ������� ������ ����
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // ������ ������ ����
       -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // ������ ����� ����
       -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // ������� ����� ����
    };

    unsigned int indices[6] = {
        0, 1, 3,
        1, 2, 3
    };
};

#endif
