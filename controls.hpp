#ifndef CONTROLS_H
#define CONTROLS_H
#include <SDL/SDL.h>
#include <iostream>
using namespace std;

class Controls{

	public:
		Controls();
		~Controls();
		
		uint logic();
		bool KeyHeld(SDLKey theKey);
		
 
	private:
		bool Keys[323];

};

#endif

