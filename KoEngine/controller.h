#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include "player.h"

class Controller {
public:
    Controller(Player& player);
    void processInput(SDL_Keycode key, bool isPressed, float deltaTime);
    void update(float deltaTime);

private:
    Player& player;
    bool moveForwardFlag, moveBackwardFlag, moveLeftFlag, moveRightFlag;
    void moveForward(float deltaTime);
    void moveBackward(float deltaTime);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
};

#endif
