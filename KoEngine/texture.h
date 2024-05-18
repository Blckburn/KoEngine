#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glad/glad.h>
#include <SDL_image.h>

class Texture {
public:
    unsigned int ID;
    Texture(const std::string& path);
    void bind() const;
private:
    void loadTexture(const std::string& path);
};

#endif
