#include "game_object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

GameObject::GameObject()
    : position(0, 0, 0), size(1, 1, 1), color(1.0f), rotation(0.0f), isSolid(false), destroyed(false) {
    initRenderData();
}

GameObject::GameObject(glm::vec3 pos, glm::vec3 size, glm::vec3 color)
    : position(pos), size(size), color(color), rotation(0.0f), isSolid(false), destroyed(false) {
    initRenderData();
}

void GameObject::initRenderData() {
    float vertices[] = {
        // Pos      // Tex
        0.5f,  0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  1.0f, 0.0f,
       -0.5f, -0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f,  0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void GameObject::draw(GLuint shaderProgram) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, size);

    GLuint modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    GLuint colorLoc = glGetUniformLocation(shaderProgram, "spriteColor");
    glUniform3f(colorLoc, color.x, color.y, color.z);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
