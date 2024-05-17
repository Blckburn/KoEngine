#include "controller.h"
#include "player.h"
#include <GLFW/glfw3.h>

void Controller::processInput(Player& player, GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        player.yAcceleration += 0.1f;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        player.yAcceleration -= 0.1f;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        player.xAcceleration -= 0.1f;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        player.xAcceleration += 0.1f;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        player.angularAcceleration -= 0.1f;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        player.angularAcceleration += 0.1f;
}
