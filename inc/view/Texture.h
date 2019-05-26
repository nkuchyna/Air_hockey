#ifndef TEXTURE_H
#define TEXTURE_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

template <typename T>

class Texture
{
public:
    Texture(T texture, int width, int height) : texture(texture), width(width), height(height) {}
    ~Texture() {}
    T    getTexture() { return this->texture; }
    int getWidth() { return this->width; }
    int getHeight() { return this->height; }
private:
    T               texture;
    int             width;
    int             height;
    float           scale;
};

#endif
