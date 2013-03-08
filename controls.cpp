#include "controls.hpp"

Controls::Controls(){
	for(int i;i<323;i++){
		Keys[i]=false;
	}
}

uint Controls::logic(){
	SDL_Event theEvent;

	while(SDL_PollEvent(&theEvent)){
		switch(theEvent.type){
		
			case SDL_KEYDOWN:
				cout << "Key pressed:"<< theEvent.key.keysym.sym <<endl;
				Keys[theEvent.key.keysym.sym]=true;
				break;
			
			case SDL_KEYUP:

				cout << "Key up:"<< theEvent.key.keysym.sym <<endl;
				Keys[theEvent.key.keysym.sym]=false;
				break;

		}
	}
	return 0x01;
}



bool Controls::KeyHeld(SDLKey theKey){
	return Keys[theKey];
}

Controls::~Controls(){

}
