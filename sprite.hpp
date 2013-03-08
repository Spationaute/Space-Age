#ifndef SPRITE_H
#define SPRITE_H
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <vector>
#include <cstdio>

typedef unsigned int uint;

using namespace std;

class Sprite{

	public:
		Sprite();
		~Sprite();
/** NOT IMPLENTED !! 
		uint save();
		uint load();
**/
		void setWidth(int val);
		void setHeight(int val);
		void setPos(int x,int y);

		void setRef(uint ref);
		void setAngle(double toSet);
	
		uint addImage(const char* toAdd);
		
		int setStep(int toSet);

		void nextStep();
		void prevStep();
		
		void transform();
		void move(int x,int y);
		
	
		SDL_Surface* getStep();
		SDL_Rect* getDest();
		uint getRef();
		double getAngle();

	private:
		uint numbImage;	
		uint step;
		SDL_Rect* dest;
		double angle;
		std::vector<SDL_Surface*> image_list;
		std::vector<SDL_Surface*> transformed_image_list;


};

#endif 
