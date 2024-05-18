#include "texture.h"
#include <iostream>

Texture::Texture(const std::string& path) {
    loadTexture(path);
}

void Texture::loadTexture(const std::string& path) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface) {
        int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);
        glGenerateMipmap(GL_TEXTURE_2D);
        SDL_FreeSurface(surface);
    }
    else {
        std::cout << "Failed to load texture: " << path << std::endl;
    }
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, ID);
}
