#ifndef PLAYER_H
#define PLAYER_H

#include <glm/glm.hpp>
#include <glad/glad.h>
#include "shader.h"
#include "texture.h"

class Player {
public:
    Player(glm::vec3 position);

    void render(const Shader& shader) const;
    glm::vec3 getPosition() const;
    void setPosition(const glm::vec3& newPosition);

private:
    void setupPlayer();
    glm::vec3 position;
    GLuint VAO, VBO, EBO;
};

#endif
