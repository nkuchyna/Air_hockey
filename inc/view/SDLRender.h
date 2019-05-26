#ifndef SDLRENDER_H
#define SDLRENDER_H
#include "IRender.h"
#include "SDLTextureFabric.h"

class SDLRender : public IRender
{
public:
    SDLRender();
    ~SDLRender();
    SDLRender(SDLRender const &src);
    SDLRender& operator=(SDLRender const &src);
    
    eKeys   keyBoardEvent() override;
    void    drawTexture(eTextures type, int x, int y) override;
    void    drawAnimation(eAnimation type, int x, int y) override;
    void    clearWindow() override;
    void    updateWindow() override;
    void    renderText(std::string text, int x, int y, eFonts font, eColors color) override;

private:
    SDLTextureFabric    *textFabric; //flyweightFabric
    SDL_Window          *window;
    SDL_Event           event;
    SDL_Renderer        *renderer;

    std::unordered_map<eKeys, SDL_Keycode>  keysMap;
    std::unordered_map<eColors, SDL_Color>  colorMap;
    void    initKeys();
    void    clearSDLRenderQuit();

    static int      imgFlags;
};

#endif