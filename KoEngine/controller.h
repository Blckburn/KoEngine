#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include "player.h"

class Controller {
public:
    Controller(Player& player);
    void processInput(SDL_Event& event, float speed);

private:
    Player& player;
};

#endif
