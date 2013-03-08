#include "game.hpp"
Game::Game(){
	//Variables
	flag=0x01;

	//Classe essentiel
	theScreen = new Screen();
	theControls = new Controls();
	theOptions = new Options();

	//Modules de SDL
	IMG_Init(IMG_INIT_PNG);	

	//Charger les options
	int opt = theOptions->load("options.opt");
	int screen_width = theOptions->getOptions("width")->intValue;
	int screen_height = theOptions->getOptions("height")->intValue;
	

	//Démarrer la fenêtre
	theScreen->setWidth(screen_width);
	theScreen->setHeight(screen_height);
	theScreen->init();
	std::cout << opt << " Options chargé." << std::endl;
	std::cout << "Width: " << screen_width << std::endl;
	std::cout << "Height:" << screen_height << std::endl;
}

uint Game::on(){
	//Game Logic

	//Make the hero!
	Sprite herospr;
	herospr.addImage("./img/spaceship.png");
	herospr.addImage("./img/spaceship2.png");
	herospr.setPos(16,16);

	Entite hero;
	hero.setSprite(&herospr);	
	hero.setPos(500,500);
	
	//Add the hero to screen
	theScreen->addEntite(&hero);
	
	//Make the ground phy
	Physique* ground = Create_Physique();
	ground->angle =90.0;
	ground->masse = 0.0;

	while(flag & 0x01){


		//Run the control logic
		theControls->logic();
		herospr.setStep(0);

			double angle = hero.getAngle();
			hero.setFriction(0.01);

			if( theControls->KeyHeld(SDLK_UP) ){
					hero.addForce( 0.1 , (hero.getHeading()+90));
					herospr.setStep(1);
			}
			
			
			if( theControls->KeyHeld(SDLK_RIGHT) ){
					hero.addRForce(0.05);
					herospr.setStep(1);
			}
			
			if( theControls->KeyHeld(SDLK_LEFT) ){
					hero.addRForce(-0.05);
					herospr.setStep(1);
			}
	
			if( theControls->KeyHeld(SDLK_ESCAPE) ){
					flag ^= 0x01;
			}
		//Ajout de la force de gravité

		
			
		
			hero.addForce(0.981 *2*(hero.getY()/500),270);
		
		hero.logic();
		//Does it "hit" the ground
		if(hero.getY()>500){
			hero.collid(ground);
		}

		//Draw the screen
		theScreen->paint();
	}

}

Game::~Game(){
	theOptions->clear();
	delete theOptions;
	IMG_Quit();
	delete theScreen;
}
