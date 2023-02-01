#include "Control.h"
#include "hero.h"
#include "enemy.h"
#include "gameStatusProvider.h"
#include "GameStatusModifier.h"
#include "objectSpawner.h"
#include "text.h"
Barnim::GameStatusProvider g_gameStatusProvider;
Barnim::GameStatusModifier g_gameStatusModifier;
Barnim::ObjectSpawner g_objectSpawner;
std::shared_ptr<Barnim::Hero> Hero;
Control app(false);
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
void attack()
{
	Hero->onAttack();
}
void pause()
{
	getGameStatusModifierInstance()->togglePause();
}

int main()
{
	g_gameStatusProvider.attachGameControl(&app);
	g_gameStatusModifier.attachGameControl(&app);
	g_objectSpawner.attachGameControl(&app);
	Hero = std::shared_ptr<Barnim::Hero>(new Barnim::Hero());
	app.addTexture("res/graphics/bg.png", 0, 0);
	Hero->LoadTexture("res/graphics/Hero.png", 200, 200, 0, 0);

	g_objectSpawner.spawn(Hero);

	app.keyboard.add_callback(moveDown, sf::Keyboard::S);
	app.keyboard.add_callback(moveUp, sf::Keyboard::W);
	app.keyboard.add_callback(moveLeft, sf::Keyboard::A);
	app.keyboard.add_callback(moveRight, sf::Keyboard::D);
	app.keyboard.add_callback(attack, sf::Keyboard::K);
	app.keyboard.add_callback(pause, sf::Keyboard::Escape);
	for (int i = 30; i < 400; i += 22)
	{
		Barnim::Enemy::SpawnNewEnemy(glm::vec2(i, i + 200));
	}
	app.run();
}