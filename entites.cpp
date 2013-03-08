#include "entites.hpp"

Entite::Entite(){
	carPhy = Create_Physique();
	time=-1;
}

void Entite::setSprite(Sprite* toSet){
	theSprite=toSet;
}

Sprite* Entite::getSprite(){
	//Applis tranformation befor drawing
	theSprite->setAngle(heading);
	return theSprite;
}

int Entite::getX(){
	return round(carPhy->x) - theSprite->getDest()->x;
}

int Entite::getY(){
	return round(carPhy->y) - theSprite->getDest()->y;
}

double Entite::getDY(){
	return carPhy->y;
}

double Entite::getDX(){
	return carPhy->x;
}


void Entite::move(double x,double y){
	carPhy->x += x;
	carPhy->y += y;
}

void Entite::setPos(double x,double y){
	carPhy->x=x;
	carPhy->y=y;
}

void Entite::setAngle(double angle){

	//Simplifier les calcule pour l'algorithm de rotation
	angle=angle<0?359:angle;
	angle=angle>360?1:angle;


	carPhy->angle=angle;

	//Change angle in sprite

}

void Entite::setForce(double force,double angle){
	carPhy->force=force;
	carPhy->angle=angle;
}

void Entite::setRForce(double force){
	carPhy->rforce=force;
}


void Entite::addForce(double force,double angle){
	// cos(a) = ad/h;
	// cos(a) * h = ad;
	double toAddX = cos(angle * ToRad) * force;
	// sin(a) = o/h
	// sin(a) * h = o;
	double toAddY = sin(angle * ToRad) * force ;

	double exAngle = carPhy->angle;
	double exForce = carPhy->force;

	double exX = (cos(exAngle * ToRad) * exForce) + toAddX;
	double exY = (sin(exAngle * ToRad) * exForce) + toAddY;
	
	// H = sqrt(((a+b)-0)²+((c+d)-0)²);
	double fforce = sqrt((exX*exX)+(exY*exY));
	
	// tan(a) = o/a;
	// a = tan⁻¹ ( o/a );
	double fangle = atan2( exY , exX ) / ToRad;

	setForce( fforce, fangle );
}

void Entite::addRForce(double force){
	carPhy->rforce += force;
}

void Entite::setFriction(double force){
	carPhy->friction = force;
}

double Entite::getForce(){
	return carPhy->force;
}

double Entite::getAngle(){
	return carPhy->angle; 
} 

void Entite::setHeading(double angle){
	angle=angle<0?359:angle;
	angle=angle>360?1:angle;

	heading=angle;
}

double Entite::getHeading(){
	return heading;
}

void Entite::logic(){
	lastX=getDX();
	lastY=getDY();

	double force = carPhy->force;
	double rforce = carPhy->rforce;
	double masse = carPhy->masse;
	//Ignorer la masse si elle égal 0
	masse= (masse==0?1:masse);

	//soh sin(a)=o/h sin(a)/h = o
	setHeading(heading + (rforce / masse));

	//Appliquer la force
	double toAddx = cos(carPhy->angle * ToRad) * force;
	double toAddy = -( sin(carPhy->angle * ToRad) * force );

	double ax = toAddx / masse;
	double ay = toAddy / masse;

	addForce( - ((carPhy->friction)*(force*masse)), carPhy->angle) ;
	double rfriction= (carPhy->friction) * (rforce*masse) ;

	//Appliquer la friction
	setRForce( rforce-rfriction);
//	carPhy->force= force-friction;

	move(ax , ay);
}


int Entite::collid(Physique* ocollided){

	double ocforce = ocollided->force;
	double ocangle = ocollided->angle;
	double ocmasse = ocollided->masse;

	double tyforce = carPhy->force;
	double tyangle =  carPhy->angle;
	double tymasse =  carPhy->masse;

	if(ocmasse<=0){
		//The mass is so enormous that is considered as infinit
		setForce((tyforce/carPhy->hardness),-tyangle);

		//Restor last position, that disble the "sinking" effect
		carPhy->x=lastX;
		carPhy->y=lastY;
		return 1;
	}

	double forcex = cos(ocangle * ToRad) * ocforce;
	double forcey = sin(ocangle * ToRad) * ocforce;

	forcex += cos(tyangle * ToRad) * tyforce;
	forcey += sin(tyangle * ToRad) * tyforce;

	double toforce = sqrt((forcex*forcex)+(forcey*forcey));
	double toangle = atan2( forcey, forcex ) / ToRad;
	
	//Perte d'énergie (friction et déformation *1.5)
	toforce = toforce/carPhy->hardness;
	
	setForce(toforce,toangle);
	return 1;
}

Entite::~Entite(){


}

