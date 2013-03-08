#ifndef PHYSIQUE_HPP
#define PHYSIQUE_HPP

struct Physique{
	//The X position of the object
	double x;

	//The Y, arrr, you know what
	double y;

	//The sum of force applied last turn
	double force;
	
	//The sum of "rotatory" force applied last turn
	double rforce;

	//Thr direction of the sum of forces
	double angle;

	//The mass of the object
	double masse;

	//The factor of friction of the objects
	double friction;

	//The hardness (more is hard, less it's bounce) 
	//( 1 is a lose less transfert (ultra bouncy!)
	double hardness;
};

Physique* Create_Physique();
Physique* Copy_Physique();
#endif
