#include "Control.h"
#include "hero.h"

// make it global to be used by keyboard
Barnim::Hero Hero;


void moveDown()
{
	Hero.onDownMovement();
}

int main(){
	Control app(false);
	app.addTexture("res/graphics/bg.png",0,0);
	Hero.LoadTexture("res/graphics/hero.png",200,200,0,0);
	app.addDrawableObject(&Hero);
	app.keyboard.add_callback(moveDown,sf::Keyboard::Down);
	app.run();
}