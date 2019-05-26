#include "SDLRender.h"
#include <iostream>

SDLRender::SDLRender() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || TTF_Init() < 0)
        throw ErrorException("Error in library initialization!");
    if(!(this->window = SDL_CreateWindow("Aero_hockey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ::gWidth, ::gHeight, SDL_WINDOW_SHOWN)))
        throw ErrorException("Error in creating window!");
    if(!(this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_PRESENTVSYNC)))
    {
        clearSDLRenderQuit();
        throw ErrorException("Error in creating renderer!");
    }
    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int inittedFlags = IMG_Init(SDLRender::imgFlags);
    if((inittedFlags&SDLRender::imgFlags) !=  SDLRender::imgFlags)
    {
        clearSDLRenderQuit();
        throw ErrorException("Error in image settings initialiazation!");
    }
    this->textFabric = new SDLTextureFabric(*this->renderer);
    initKeys();
    colorMap[ORDINARY] = {200, 200, 200, 255};
    colorMap[HIGHLIGHT] = {17, 67, 67, 255};
}

SDLRender::~SDLRender() {
    clearSDLRenderQuit();
}

SDLRender::SDLRender(SDLRender const &src) {
    *this = src;
}

SDLRender &SDLRender::operator=(SDLRender const &src) {
    if(&src != this)
    {
        SDL_DestroyWindow(this->window);
        this->window = src.window;
        this->event = src.event;
        SDL_DestroyRenderer(this->renderer);
        this->renderer = src.renderer;
    }
    return (*this);
}

void    SDLRender::clearSDLRenderQuit()
{
    if(this->renderer)
        SDL_DestroyRenderer(this->renderer);
    if(this->window)
    SDL_DestroyWindow(this->window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

eKeys   SDLRender::keyBoardEvent()
{
    while(SDL_PollEvent(&this->event))
    {
        if(this->event.type == SDL_QUIT || (this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[EXIT]))
            return EXIT;
        if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[UP])
            return UP;
        else if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[RIGHT])
            return RIGHT;
        else if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[DOWN])
            return DOWN;
        else if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[LEFT])
            return LEFT;
        else if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[MENU])
            return MENU;
        else if(this->event.type == SDL_KEYDOWN && this->event.key.keysym.sym == keysMap[ENTER])
            return ENTER;
        else if(this->event.type == SDL_KEYDOWN)
            return DEFAULT; 
    }
    return NONE;
}

void    SDLRender::drawTexture(eTextures type, int x, int y)
{
    if (type > TEXTURES_NBR || type < 0)
        return;
    Texture<SDL_Texture*>*    textureObj = this->textFabric->getSpriteTexture(type);
    SDL_Rect place = {x, y, textureObj->getWidth(), textureObj->getHeight()};
    SDL_RenderCopy(this->renderer, textureObj->getTexture(), NULL, &place);
}

void    SDLRender::drawAnimation(eAnimation type, int x, int y)
{
    if (type > ANIMATIONS_NBR || type < 0)
        return;

    unsigned frame_start = SDL_GetTicks();
    unsigned time = 0;
    unsigned delay = 100;    
    Texture<SDL_Texture*>*    textureObj = this->textFabric->getAnimationTexture(type);
    SDL_Rect place = {x, y, textureObj->getWidth(), textureObj->getHeight()};
    SDL_RenderCopy(this->renderer, textureObj->getTexture(), NULL, &place);
    if((time = SDL_GetTicks() - frame_start) < delay)
        SDL_Delay(delay - time);
}

void    SDLRender::updateWindow()
{
    SDL_RenderPresent(this->renderer);
}

void    SDLRender::renderText(std::string text, int x, int y, eFonts type, eColors color)
{
    if(type < 0 || type > FONTS_NBR)
        return;
    TTF_Font        *font = this->textFabric->getFont(type);
    SDL_Surface     *textSurface = TTF_RenderText_Solid(font, text.c_str(), colorMap[color]);
    SDL_Rect        place = {x, y, textSurface->w, textSurface->h};
    SDL_Texture     *texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
    SDL_RenderCopy(this->renderer, texture, NULL, &place);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(texture);
}

void    SDLRender::initKeys()
{
    keysMap[UP] = SDLK_UP;
    keysMap[RIGHT] = SDLK_RIGHT;
    keysMap[DOWN] = SDLK_DOWN;
    keysMap[LEFT] = SDLK_LEFT;
    keysMap[EXIT] = SDLK_ESCAPE;
    keysMap[MENU] = SDLK_m;
    keysMap[ENTER] = SDLK_RETURN;
}

void    SDLRender::clearWindow()
{
    SDL_RenderClear(this->renderer);
}

int     SDLRender::imgFlags = IMG_INIT_JPG|IMG_INIT_PNG;