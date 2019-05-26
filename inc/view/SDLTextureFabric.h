#ifndef SDL_TEXTURE_FABRIC_H
#define SDL_TEXTURE_FABRIC_H
#include <unordered_map>
#include "Game.h"
#include "Animation.h"

class SDLTextureFabric
{
public:
    SDLTextureFabric(SDL_Renderer &renderer);
    ~SDLTextureFabric();
    Texture<SDL_Texture*>*    getSpriteTexture(eTextures type);
    Texture<SDL_Texture*>*    getAnimationTexture(eAnimation type);
    TTF_Font*   getFont(eFonts font);
    static bool   getSizes(eTextures type, int *width, int *height);
    
private:
    std::unordered_map<eTextures, std::string>         texturePath;
    std::unordered_map<eFonts, std::string>            fontPath;
    std::unordered_map<eFonts, TTF_Font*>              fontMap;
    std::unordered_map<eAnimation, std::vector<std::string>>         animationPath;
    static std::unordered_map<eTextures, Texture<SDL_Texture*>*>     textureMap;
    static std::unordered_map<eAnimation, Animation*>     animationMap;

    int             fontSize[FONTS_NBR];
    SDL_Renderer    &renderer;
    Texture<SDL_Texture*>*        loadTexture(eTextures type);
    Texture<SDL_Texture*>*        loadTextureByPath(std::string &path);
    Animation*                    loadAnimation(eAnimation type);
};

#endif