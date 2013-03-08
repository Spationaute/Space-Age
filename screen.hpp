#ifndef SCREEN_H
#define SCREEN_H
#include <SDL/SDL.h>
#include <iostream>
#include <vector>
#include <SDL/SDL_rotozoom.h>
#include "sprite.hpp"
#include "entites.hpp"


class Screen{
	

	public:
		Screen();
		~Screen();
		
		int  init();
		void paint();

		int addSprite(Sprite* toReg);
		int addEntite(Entite* toAdd);
		
		void setWidth(int value);
		void setHeight(int value);
		void setDepth(int value);

	private:

		int swidth;
		int sheight;
		int sdepth;
		SDL_Surface* mwindow;
	
		std::vector<Entite*> entiteListe;
		std::vector<Sprite*> spriteListe;
};

#endif
