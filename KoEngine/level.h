#ifndef LEVEL_H
#define LEVEL_H

#include "shader.h"

class Level {
public:
    void drawFloor(const Shader& shader) const;
    void render(const Shader& shader) const;
private:
    unsigned int VAO;
};

#endif // LEVEL_H
