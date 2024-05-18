//#include "controller.h"
//
//Controller::Controller(Player& player) : player(player) {}
//
//void Controller::processInput(const SDL_Event& event, float deltaTime) {
//    if (event.type == SDL_KEYDOWN) {
//        switch (event.key.keysym.sym) {
//        case SDLK_w:
//            player.setVelocityY(player.getVelocityY() + player.getAcceleration() * deltaTime);
//            break;
//        case SDLK_s:
//            player.setVelocityY(player.getVelocityY() - player.getAcceleration() * deltaTime);
//            break;
//        case SDLK_a:
//            player.setVelocityX(player.getVelocityX() - player.getAcceleration() * deltaTime);
//            break;
//        case SDLK_d:
//            player.setVelocityX(player.getVelocityX() + player.getAcceleration() * deltaTime);
//            break;
//        }
//    }
//}
