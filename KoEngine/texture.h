#ifndef TEXTURE_H
#define TEXTURE_H

class Texture {
public:
    unsigned int ID;

    Texture(const char* imagePath);

    void bind() const;

private:
    void loadTexture(const char* imagePath);
};

#endif // TEXTURE_H
