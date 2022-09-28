#include "Control.h"
#include "hero.h"
#include "enemy.h"
#include "gameStatusProvider.h"

Barnim::GameStatusProvider g_gameStatusProvider;


Barnim::Hero Hero;
Barnim::Enemy Enemy;
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
int main(){
	Control app(false);

	g_gameStatusProvider.attachGameControl(&app);
	app.addTexture("res/graphics/bg.png",0,0);
	Hero.LoadTexture("res/graphics/hero.png",200,200,0,0);
	app.addDrawableObject(&Hero);
	app.keyboard.add_callback(moveDown,sf::Keyboard::S);
	app.keyboard.add_callback(moveUp,sf::Keyboard::W);
	app.keyboard.add_callback(moveLeft,sf::Keyboard::A);
	app.keyboard.add_callback(moveRight,sf::Keyboard::D);
	Enemy.LoadTexture("res/graphics/enemy.png",300,300,0,0);
	app.addDrawableObject(&Enemy);
	app.run();
}