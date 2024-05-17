#pragma once

class Player;
struct GLFWwindow;

class Controller {
public:
    void processInput(Player& player, GLFWwindow* window);
};
