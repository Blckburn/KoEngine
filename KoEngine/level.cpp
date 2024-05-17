#include "level.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void Level::drawFloor(const Shader& shader) const {
    shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Level::render(const Shader& shader) const {
    drawFloor(shader);
}
