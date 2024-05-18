//#include "player.h"
//#include <GL/glew.h>
//#include <SDL_image.h>
//
//Player::Player(glm::vec3 position, const Texture& texture)
//    : position(position), texture(texture), velocity(0.0f), acceleration(1.0f, 1.0f, 0.0f) {
//    setupPlayer();
//}
//
//void Player::setupPlayer() {
//    float playerVertices[] = {
//        // позиции          // текстурные координаты
//        0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
//        0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
//       -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
//
//        0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
//       -0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
//       -0.5f,  0.5f, 0.0f,  0.0f, 1.0f
//    };
//
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(playerVertices), playerVertices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    glBindVertexArray(0);
//}
//
//void Player::render(const Shader& shader) const {
//    texture.bind();
//    glBindVertexArray(VAO);
//    glDrawArrays(GL_TRIANGLES, 0, 6);
//    glBindVertexArray(0);
//}
