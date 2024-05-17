#include "controller.h"
#include "player.h"

Controller::Controller(Player& player) : player(player) {}

void Controller::processInput(SDL_Event& event, float deltaTime) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    player.xAcceleration = 0.0f;
    player.yAcceleration = 0.0f;
    player.angularAcceleration = 0.0f; // Убедитесь, что этот член используется

    if (currentKeyStates[SDL_SCANCODE_W]) {
        player.yAcceleration = 1.0f;
    }
    if (currentKeyStates[SDL_SCANCODE_S]) {
        player.yAcceleration = -1.0f;
    }
    if (currentKeyStates[SDL_SCANCODE_A]) {
        player.xAcceleration = -1.0f;
    }
    if (currentKeyStates[SDL_SCANCODE_D]) {
        player.xAcceleration = 1.0f;
    }
    if (currentKeyStates[SDL_SCANCODE_Q]) {
        player.angularAcceleration = -1.0f;
    }
    if (currentKeyStates[SDL_SCANCODE_E]) {
        player.angularAcceleration = 1.0f;
    }

    player.xAcceleration *= deltaTime;
    player.yAcceleration *= deltaTime;
    player.angularAcceleration *= deltaTime; // Инициализация углового ускорения
}
