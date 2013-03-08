#include "sprite.hpp"

Sprite::Sprite(){
	numbImage=0;
	step=0;
	angle=0;
	dest=new SDL_Rect();
	dest->x=0;
	dest->y=0;
	dest->w=0;
	dest->h=0;
}

void Sprite::setWidth(int val){
	dest->w=val;
}

void Sprite::setHeight(int val){
	dest->h=val;
}

void Sprite::setPos(int x,int y){
	dest->x=x;
	dest->y=y;
}

uint Sprite::addImage(const char* toAdd){
	printf("Chargement de l'image: \"%s\"\n",toAdd);
	SDL_Surface* temp= IMG_Load(toAdd);
	if(temp == NULL){
		printf("Error de chargement de l'image: \"%s\"\n",toAdd);
	}
	image_list.push_back(temp);
	numbImage++;
	this->transform();
}

void Sprite::nextStep(){
	if(step < numbImage-1){
		step++;
	}else{
		step=0;
	}
}

void Sprite::prevStep(){
	if(step > 1){
		step--;
	}else{
		step=numbImage;
	}
}

int Sprite::setStep(int toSet){
	if( (toSet < numbImage) && (toSet > -1)){
		step=toSet;
	}
	return step;
}

SDL_Surface* Sprite::getStep(){
	return transformed_image_list.at(step);
}


SDL_Rect* Sprite::getDest(){
	return dest;
}

void Sprite::setAngle(double toSet){
	angle = toSet;

	//Simplifier les calcule pour l'algorithm de rotation
	angle=angle<0?360:angle;
	angle=angle>360?0:angle;

	//Effectuer les transformation sur le sprite
	this->transform();
}


void Sprite::move(int x,int y){
	dest->x = dest->x + x;
	dest->y = dest->y + y;
}

void Sprite::transform(){
	//Clean memory
	for(int i=0;i<transformed_image_list.size();++i){
		SDL_FreeSurface(transformed_image_list.at(i));
	}
	transformed_image_list.clear();

	//Make the new rotated sprite
	for(int i=0;i<image_list.size();++i){
		transformed_image_list.push_back(rotozoomSurface(image_list.at(i),this->getAngle(),1,SMOOTHING_OFF));
	}	
}

double Sprite::getAngle(){
	return angle;
}

Sprite::~Sprite(){

}
