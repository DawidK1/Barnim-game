#ifndef GAME_STATUS_PROVIDER_H
#define GAME_STATUS_PROVIDER_H
#include "DrawableObject.h"
#include "control.h"
#include "hero.h"
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
	vector<Barnim::Hero *> getHeroes();
};

}; // namespace Barnim

Barnim::GameStatusProvider *getGameStatusProviderInstance();
#endif