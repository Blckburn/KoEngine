#include "level.h"
#include <iostream>

void Level::drawFloor() {
    // ���������� ������� drawFloor
}

void Level::render(const Shader& shader) const {
    // ���������, ��� VAO ��������� � ���������������
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}
