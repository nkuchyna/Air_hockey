#include "SDLTextureFabric.h"

SDLTextureFabric::SDLTextureFabric(SDL_Renderer &renderer) : renderer(renderer)
{
    texturePath[MENU_BACKGROUND] = "./resources/gtable_main.png";
    texturePath[GAME_BACKGROUND] = "./resources/gtable.png";
    texturePath[PUCK] = "./resources/grpuck.png";
    texturePath[PADDLE_EN] = "./resources/rpaddle.png";
    texturePath[PADDLE_MY] = "./resources/gpaddle.png";

    fontPath[MENU_FONT] = "./resources/alba.super.ttf";
    fontPath[GAME_FONT] = "./resources/alba.super.ttf";
    fontPath[INFO_FONT] = "./resources/alba.super.ttf";
    fontPath[WIN_FAIL_FONT] = "./resources/alba.super.ttf";

    fontSize[MENU_FONT] = ::gHeight * 0.04;
    fontSize[GAME_FONT] = ::gHeight * 0.4;
    fontSize[INFO_FONT] = ::gHeight * 0.025;
    fontSize[WIN_FAIL_FONT] = ::gHeight * 0.05;

    animationPath[NEXT_LEVEL_ANIMATION].reserve(6);
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext1.png");
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext2.png");
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext3.png");
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext4.png");
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext5.png");
    animationPath[NEXT_LEVEL_ANIMATION].push_back("./resources/gnext6.png");
 }

SDLTextureFabric::~SDLTextureFabric()
{
    for(auto &it : textureMap)
        delete it.second;
    for(auto &it : animationMap)
        delete it.second;
}

Texture<SDL_Texture*>*     SDLTextureFabric::loadTexture(eTextures type)
{
    SDL_Texture*    texture = NULL;
    SDL_Surface*    textSurface = NULL;
    Texture<SDL_Texture*>   *textObj;

    if(!(textSurface = IMG_Load(texturePath[type].c_str())))
        std::cout << " Reason1: " << SDL_GetError() << std::endl;
    if(!(texture = SDL_CreateTextureFromSurface(&this->renderer, textSurface)))
        throw ErrorException("Error in texture loading by path: " + texturePath[type] + "!");
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    textObj = new Texture<SDL_Texture*>(texture, textSurface->w, textSurface->h);
    SDL_FreeSurface(textSurface);
    return textObj;
}

Texture<SDL_Texture*>*     SDLTextureFabric::loadTextureByPath(std::string &path)
{
    SDL_Texture*    texture = NULL;
    SDL_Surface*    textSurface = NULL;
    Texture<SDL_Texture*>   *textObj;

    if(!(textSurface = IMG_Load(path.c_str())))
        std::cout << " Reason1: " << SDL_GetError() << std::endl;
    if(!(texture = SDL_CreateTextureFromSurface(&this->renderer, textSurface)))
        throw ErrorException("Error in texture loading by path: " + path + "!");
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    textObj = new Texture<SDL_Texture*>(texture, textSurface->w, textSurface->h);
    SDL_FreeSurface(textSurface);
    return textObj;
}

Animation*  SDLTextureFabric::loadAnimation(eAnimation type)
{
    Animation*      tmpAnimation = new Animation();
    Texture<SDL_Texture*> *tmpTexture;
    
    std::vector<std::string> vect = animationPath[type];
    for(auto &it : vect)
    {
        if((tmpTexture = loadTextureByPath(it)))
            tmpAnimation->addSprite(tmpTexture);
    }
    return tmpAnimation;
}

Texture<SDL_Texture*>*     SDLTextureFabric::getSpriteTexture(eTextures type)
{
    if(textureMap.find(type) == textureMap.end() && texturePath.find(type) != texturePath.end())
        textureMap[type] = loadTexture(type);
    if(!textureMap[type]->getTexture() || texturePath.find(type) == texturePath.end())
        throw ErrorException("Error! There in texture load!");
    return textureMap[type];
}

Texture<SDL_Texture*>*    SDLTextureFabric::getAnimationTexture(eAnimation type)
{        
    if(animationMap.find(type) == animationMap.end())
        animationMap[type] = loadAnimation(type);
    if(!animationMap[type]->getSprite())
        throw ErrorException("Error! There in animation load!");
    return animationMap[type]->getSprite();
}


TTF_Font*     SDLTextureFabric::getFont(eFonts type)
{
    if(fontMap.find(type) == fontMap.end() && fontPath.find(type) != fontPath.end())
        fontMap[type] = TTF_OpenFont(fontPath[type].c_str(), fontSize[type]);
    if(!fontMap[type] || fontPath.find(type) == fontPath.end())
        throw ErrorException("Error in the font load!");
    return (fontMap[type]);
}

bool   SDLTextureFabric::getSizes(eTextures type, int *width, int *height)
{
    if (type > TEXTURES_NBR || type < 0)
        return false;
    *width = SDLTextureFabric::textureMap[type]->getWidth();
    *height = SDLTextureFabric::textureMap[type]->getHeight();
    return true;
}
//************************************************************
std::unordered_map<eTextures, Texture<SDL_Texture*>*>       SDLTextureFabric::textureMap;
std::unordered_map<eAnimation, Animation*>                  SDLTextureFabric::animationMap;
