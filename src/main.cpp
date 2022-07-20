#include "Control.h"
#include "hero.h"

// make it global to be used by keyboard
Barnim::Hero Hero;


void moveDown()
{
	Hero.onDownMovement();
}
void moveUp()
{
	Hero.onUpMovement();
}
void moveLeft()
{
	Hero.onLeftMovement();
}
void moveRight()
{
	Hero.onRightMovement();
}
void moveFast()
{
	Hero.increaseSpeed();
}
void moveSlow()
{
	Hero.decreaseSpeed();
}
int main(){
	Control app(false);
	app.addTexture("res/graphics/bg.png",0,0);
	Hero.LoadTexture("res/graphics/hero.png",200,200,0,0);
	app.addDrawableObject(&Hero);
	app.keyboard.add_callback(moveDown,sf::Keyboard::S);
	app.keyboard.add_callback(moveUp,sf::Keyboard::W);
	app.keyboard.add_callback(moveLeft,sf::Keyboard::A);
	app.keyboard.add_callback(moveRight,sf::Keyboard::D);
	app.keyboard.add_callback(moveFast,sf::Keyboard::P);
	app.keyboard.add_callback(moveSlow,sf::Keyboard::L);
	app.run();
}