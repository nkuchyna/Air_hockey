#include "Animation.h"
#include <iostream>

Animation::Animation(){
	slideIndex = 0;
}

Animation::~Animation()
{
	for(auto &it : slides)
        delete it;
}

Texture<SDL_Texture*>*    Animation::getSprite()
{
	Texture<SDL_Texture*>* tmp = nullptr;
	int slideIndex_tmp = 0;
	(slideIndex > 0) ? tmp = slides.at(slideIndex - 1) : tmp = slides.at(slideIndex);
	updateSlideIndex();
	return tmp;
}

void	Animation::addSprite(Texture<SDL_Texture*>* sprite)
{
	slides.push_back(sprite);
}

void	Animation::updateSlideIndex()
{
	++slideIndex;
	if(slideIndex > slides.size())
		slideIndex = 0;
}
