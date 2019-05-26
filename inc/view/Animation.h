#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include "Texture.h"

class Animation
{
public:
	Animation();
	~Animation();
	Texture<SDL_Texture*>*    getSprite();
	void	addSprite(Texture<SDL_Texture*>* sprite);

private:
	std::vector<Texture<SDL_Texture*>*>		slides;
	int		slideIndex;
	void	updateSlideIndex();
};

#endif