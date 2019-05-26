#include "SPlayerSDL.h"

SPlayerSDL::SPlayerSDL() {
    init();
}

SPlayerSDL::SPlayerSDL(const SPlayerSDL &obj) {
    *this = obj;
}

SPlayerSDL& SPlayerSDL::operator=(const SPlayerSDL &obj) {

    if (&obj != this)
    {
        for(int i = 0; i < MUSIC_NBR; i++)
        {
            if(this->_musicArr[i])
                Mix_FreeMusic(this->_musicArr[i]);
            if(obj._musicArr[i])
                this->_musicArr[i] = obj._musicArr[i];
        }
        for(int i = 0; i < SOUNDS_NBR; i++)
        {
            if(this->_soundArr[i])
                Mix_FreeChunk(this->_soundArr[i]);
            if(obj._soundArr[i])
                this->_soundArr[i] = obj._soundArr[i];
        }
    }
    return (*this);
}

SPlayerSDL::~SPlayerSDL(){

    clearResources();
    Mix_CloseAudio();
    SDL_Quit();
}

void    SPlayerSDL::playSound(eSounds type) {

    if (type < 0 || type > SOUNDS_NBR)
        return;
    stopSound();
    Mix_PlayChannel(-1, _soundArr[type], 0);
}

void    SPlayerSDL::playMusic(eMusic type)
{
    if (type < 0 || type > MUSIC_NBR)
        return;
    stopMusic();
    stopSound();
    Mix_PlayMusic(_musicArr[type], -1);
}

void    SPlayerSDL::stopSound() {

    Mix_HaltChannel(-1);
}

void    SPlayerSDL::stopMusic() {

    Mix_HaltMusic();
}

void    SPlayerSDL::init() {

    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) == -1)
    {
        throw (ErrorException("Error! Can not init SDL_Mixer!"));
    }
    for(int i = 0; i < MUSIC_NBR; i++)
        _musicArr[i] = NULL;
    for(int i = 0; i < SOUNDS_NBR; i++)
        _soundArr[i] = NULL;
    this->loadResources();
}

void    SPlayerSDL::loadResources() {

    _soundArr[CLICK] = Mix_LoadWAV("./resources/pop.mp3");
    _soundArr[MOVE] = Mix_LoadWAV("./resources/move.mp3");
    _soundArr[WIN_SOUND] = Mix_LoadWAV("./resources/win.mp3");
    _soundArr[FAIL_SOUND] = Mix_LoadWAV("./resources/puppy_love_sting.mp3");
    for(int i = 0; i < SOUNDS_NBR; i++)
    {
        if (!_soundArr[i])
        {
            clearResources();
            throw (ErrorException("Error in sounds download!"));
        }
    }
    _musicArr[MENU_MUSIC] = Mix_LoadMUS("./resources/good_starts.mp3");
    _musicArr[GAME_MUSIC] = Mix_LoadMUS("./resources/Robot_Boogie.mp3");
    for(int i = 0; i < MUSIC_NBR; i++)
    {
        if (!_musicArr[i])
        {
            clearResources();
            throw (ErrorException("Error in music download!"));
        }
    }
}

void    SPlayerSDL::clearResources() {

    for(int i = 0; i < MUSIC_NBR; i++)
    { 
        if (_musicArr[i])
            Mix_FreeMusic(_musicArr[i]);
    }
    for(int i = 0; i < SOUNDS_NBR; i++)
    { 
        if (_soundArr[i])
           Mix_FreeChunk(_soundArr[i]);
    }
}

SPlayerSDL   SPlayerSDL::shared;
