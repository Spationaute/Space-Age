#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <math.h>
#include <SDL/SDL_image.h>
#include "screen.hpp"
#include "entites.hpp"
#include "sprite.hpp"
#include "controls.hpp"
#include "options.hpp"
#include "physique.hpp"


class Game{
	public:
		Game();
		~Game();
	
		uint on();
	private:

		uint flag;
		Screen* theScreen;
		Controls* theControls;
		Options* theOptions;

};

#endif
