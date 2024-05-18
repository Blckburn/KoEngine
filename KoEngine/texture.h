#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <string>

class Texture {
public:
    GLuint ID;
    std::string type;
    std::string path;

    Texture() : ID(0) {}  // Конструктор по умолчанию
    Texture(const char* imagePath);

    void bind() const;
};

#endif
