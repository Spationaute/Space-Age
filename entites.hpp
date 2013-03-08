#ifndef ENTITES_H
#define ENTITES_H
#include "sprite.hpp"
#include "options.hpp"
#include "physique.hpp"
#include <SDL/SDL.h>
#include <math.h>

#ifndef TORAD 
#define TORAD
	const double ToRad = 3.14159265/180.000;
#endif
class Entite{
	public:
		Entite();
		~Entite();
	
		void setSprite(Sprite* toSet);
		Sprite* getSprite();

		void setPos(double x,double y);
		void setForce(double force, double angle);
		void setFriction(double force);
		void setRForce(double force);

		void addForce(double force, double angle);
		void addRForce(double force);

		void setAngle(double angle);
		void setHeading(double angle);	
		double getHeading();
		
		int getX();
		int getY();

		double getDX();
		double getDY();

		void move(double x, double y);
		void logic();
		int collid(Physique* ocollided);


		double getForce();
		double getAngle();

	private:
		double heading;
		Physique* carPhy;
		Sprite* theSprite;
		double lastX;
		double lastY;
		int time;


};


#endif
