#include "level.h"
#include <iostream>

void Level::drawFloor() {
    // Реализация функции drawFloor
}

void Level::render(const Shader& shader) const {
    // Убедитесь, что VAO определен и инициализирован
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
