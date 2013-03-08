#include "physique.hpp" 

Physique* Create_Physique(){
	Physique* temp = new Physique;
	temp->x=0;
	temp->y=0;
	temp->force=0;
	temp->rforce=0;
	temp->angle=0;
	temp->masse=1;
	temp->friction=0;
	temp->hardness=1;
	return temp;
}

Physique* Copy_Physique(Physique* toCopy){
	Physique* temp = new Physique;
	temp->x=toCopy->x;	
	temp->y=toCopy->y;	
	temp->force=toCopy->force;	
	temp->rforce=toCopy->rforce;	
	temp->angle=toCopy->angle;	
	temp->masse=toCopy->masse;	
	temp->friction=toCopy->friction;
	temp->hardness=toCopy->hardness;
	return temp;
}
