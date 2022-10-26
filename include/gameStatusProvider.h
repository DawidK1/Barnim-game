#ifndef GAME_STATUS_PROVIDER_H
#define GAME_STATUS_PROVIDER_H
#include "drawableObject.h"
#include "control.h"
#include "hero.h"
#include "enemy.h"
using namespace std;
namespace Barnim
{
	
class GameStatusProvider
{
  private:
	Control *controlPtr;

  public:
	GameStatusProvider() { controlPtr = NULL; };
	void attachGameControl(Control *control);
	vector<shared_ptr<Barnim::Hero>> getHeroes();
	vector<shared_ptr<Barnim::Enemy>> getEnemies();
};

}; // namespace Barnim

Barnim::GameStatusProvider *getGameStatusProviderInstance();
#endif