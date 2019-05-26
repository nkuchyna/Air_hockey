#ifndef ISPLAYER_H
#define ISPLAYER_H

enum    eSounds
{
    CLICK,
    MOVE,
    WIN_SOUND,
    FAIL_SOUND,
    SOUNDS_NBR
};

enum eMusic
{
    MENU_MUSIC,
    GAME_MUSIC,
    MUSIC_NBR
};

class   ISPlayer
{
public:
    virtual void    playSound(eSounds type) = 0;
    virtual void    playMusic(eMusic type) = 0;

    virtual void    stopSound() = 0;
    virtual void    stopMusic() = 0;

    virtual ~ISPlayer() {}
};

#endif
