#include "screen.hpp"

Screen::Screen(){
	//Variables
	swidth=640;
	sheight=480;
	sdepth=24;

	/** Starting video, get error if needed **/
	int isOk = SDL_Init( SDL_INIT_VIDEO );

	if(isOk==-1){
		std::cout << "SDL not initialized :" << SDL_GetError() << std::endl;
	}
	
	//toPaintList.clear();
	spriteListe.clear();

	
}

int Screen::init(){
	mwindow = SDL_SetVideoMode(swidth,sheight,sdepth,SDL_HWSURFACE);
}

void Screen::paint(){
	//Clear the screen
	SDL_Rect screen_rect;
	screen_rect.x=0;
	screen_rect.y=0;
	screen_rect.w=mwindow->w;
	screen_rect.h=mwindow->h;

	SDL_FillRect(mwindow,&screen_rect,0x00000000);

	//Draw the sprites
	for(int i=0;i<spriteListe.size();++i){

		//Apply surface 
		Sprite* temp = spriteListe.at(i);
		//Get the center of the sprite
	
		SDL_BlitSurface(temp->getStep(),NULL,mwindow,temp->getDest());

	}

	//Draw entité
	for(int i=0;i<entiteListe.size();++i){

		//Apply surface 
		Entite* temp = entiteListe.at(i);
		SDL_Rect* tempRect = new SDL_Rect();
		tempRect->x = temp->getX() - temp->getSprite()->getStep()->w/2;;
		tempRect->y = temp->getY() - temp->getSprite()->getStep()->h/2;;

		SDL_BlitSurface(temp->getSprite()->getStep(),NULL,mwindow,tempRect);
		delete tempRect;

	}
	
	SDL_Flip(mwindow);

}

void Screen::setWidth(int value){
	swidth=value;
}

void Screen::setHeight(int value){
	sheight=value;
}

void Screen::setDepth(int value){
	sdepth=value;
}
int Screen::addSprite(Sprite* toReg){
	spriteListe.push_back(toReg);
	return 1;
}

int Screen::addEntite(Entite* toAdd){
	entiteListe.push_back(toAdd);
	return 1;
}

/**
int Screen::register(Sprite* toReg){
	spriteList.push_back(toReg);
}
**/

Screen::~Screen(){
	SDL_Quit();
}
