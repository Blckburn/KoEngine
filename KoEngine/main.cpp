#include <SDL.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "shader.h"
#include "camera.h"
#include "level.h"
#include "player.h"
#include "physics.h"
#include "controller.h"

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;

Camera camera(glm::vec3(0.0f, 2.0f, 5.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

void mouseCallback(SDL_Event& event);

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("KoEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    Shader shader("vertex_shader.glsl", "fragment_shader.glsl");
    Level level;
    Player player(glm::vec3(0.0f, 0.5f, 0.0f));

    Uint32 lastTime = SDL_GetTicks();

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_MOUSEMOTION) {
                mouseCallback(event);
            }
            else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                bool isKeyDown = (event.type == SDL_KEYDOWN);
                Controller::processInput(event.key.keysym.sym, isKeyDown, player);
            }
        }

        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        Physics::update(player, deltaTime);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.use();
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.GetViewMatrix();
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        glm::mat4 model = glm::translate(glm::mat4(1.0f), player.getPosition());
        shader.setMat4("model", model);
        player.render(shader);

        level.render(shader);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void mouseCallback(SDL_Event& event) {
    if (firstMouse) {
        lastX = event.motion.x;
        lastY = event.motion.y;
        firstMouse = false;
    }

    float xOffset = event.motion.x - lastX;
    float yOffset = lastY - event.motion.y;
    lastX = event.motion.x;
    lastY = event.motion.y;

    float sensitivity = 0.1f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    camera.ProcessMouseMovement(xOffset, yOffset);
}
