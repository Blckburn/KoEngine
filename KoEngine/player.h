//#ifndef PLAYER_H
//#define PLAYER_H
//
//#include <glm/glm.hpp>
//#include "texture.h"
//
//class Player {
//public:
//    Player(glm::vec3 position, const Texture& texture);
//    void render(const Shader& shader) const;
//
//    glm::vec3 getPosition() const { return position; }
//    void setPosition(const glm::vec3& pos) { position = pos; }
//
//    glm::vec3 getVelocity() const { return velocity; }
//    void setVelocity(const glm::vec3& vel) { velocity = vel; }
//
//    float getVelocityX() const { return velocity.x; }
//    float getVelocityY() const { return velocity.y; }
//    void setVelocityX(float velX) { velocity.x = velX; }
//    void setVelocityY(float velY) { velocity.y = velY; }
//
//    glm::vec3 getAcceleration() const { return acceleration; }
//
//private:
//    void setupPlayer();
//
//    glm::vec3 position;
//    glm::vec3 velocity;
//    glm::vec3 acceleration;
//    const Texture& texture;
//
//    unsigned int VAO, VBO;
//};
//
//#endif // PLAYER_H
