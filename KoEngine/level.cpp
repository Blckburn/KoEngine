#include "level.h"
#include <glad/glad.h>

Level::Level(const Texture& texture) : texture(texture) {
    setupLevel();
}

void Level::setupLevel() {
    float levelVertices[] = {
        // positions          // texture coords
        5.0f,  0.0f,  5.0f,  5.0f, 0.0f,
       -5.0f,  0.0f,  5.0f,  0.0f, 0.0f,
       -5.0f,  0.0f, -5.0f,  0.0f, 5.0f,

        5.0f,  0.0f,  5.0f,  5.0f, 0.0f,
       -5.0f,  0.0f, -5.0f,  0.0f, 5.0f,
        5.0f,  0.0f, -5.0f,  5.0f, 5.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(levelVertices), levelVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Level::render(const Shader& shader) const {
    texture.bind();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
