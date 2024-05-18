#include "controller.h"

Controller::Controller(Player& player)
    : player(player), moveForwardFlag(false), moveBackwardFlag(false), moveLeftFlag(false), moveRightFlag(false) {}

void Controller::processInput(SDL_Keycode key, bool isPressed, float deltaTime) {
    switch (key) {
    case SDLK_w:
        moveForwardFlag = isPressed;
        break;
    case SDLK_s:
        moveBackwardFlag = isPressed;
        break;
    case SDLK_a:
        moveLeftFlag = isPressed;
        break;
    case SDLK_d:
        moveRightFlag = isPressed;
        break;
    }
}

void Controller::update(float deltaTime) {
    if (moveForwardFlag) moveForward(deltaTime);
    if (moveBackwardFlag) moveBackward(deltaTime);
    if (moveLeftFlag) moveLeft(deltaTime);
    if (moveRightFlag) moveRight(deltaTime);
}

void Controller::moveForward(float deltaTime) {
    player.setPosition(player.getPosition() + glm::vec3(0.0f, 0.0f, -1.0f) * deltaTime);
}

void Controller::moveBackward(float deltaTime) {
    player.setPosition(player.getPosition() + glm::vec3(0.0f, 0.0f, 1.0f) * deltaTime);
}

void Controller::moveLeft(float deltaTime) {
    player.setPosition(player.getPosition() + glm::vec3(-1.0f, 0.0f, 0.0f) * deltaTime);
}

void Controller::moveRight(float deltaTime) {
    player.setPosition(player.getPosition() + glm::vec3(1.0f, 0.0f, 0.0f) * deltaTime);
}
