#include "Control.h"
#include "hero.h"
#include "enemy.h"
#include "gameStatusProvider.h"
#include "objectSpawner.h"
Barnim::GameStatusProvider g_gameStatusProvider;
Barnim::ObjectSpawner g_objectSpawner;

std::shared_ptr<Barnim::Hero> Hero;

void moveDown()
{
	Hero->onDownMovement();
}
void moveUp()
{
	Hero->onUpMovement();
}
void moveLeft()
{
	Hero->onLeftMovement();
}
void moveRight()
{
	Hero->onRightMovement();
}
int main()
{
	Control app(false);

	g_gameStatusProvider.attachGameControl(&app);
	g_objectSpawner.attachGameControl(&app);

	Hero = std::shared_ptr<Barnim::Hero>(new Barnim::Hero());

	app.addTexture("res/graphics/bg.png", 0, 0);
	Hero->LoadTexture("res/graphics/Hero.png", 200, 200, 0, 0);

	app.addDrawableObject(Hero);

	app.keyboard.add_callback(moveDown, sf::Keyboard::S);
	app.keyboard.add_callback(moveUp, sf::Keyboard::W);
	app.keyboard.add_callback(moveLeft, sf::Keyboard::A);
	app.keyboard.add_callback(moveRight, sf::Keyboard::D);
	for (int i = 30; i < 400; i += 22)
	{
		Barnim::Enemy::SpawnNewEnemy(glm::vec2(i, i + 200));
	}
	app.run();
}