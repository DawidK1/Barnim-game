#ifndef GAME_STATUS_PROVIDER_H
#define GAME_STATUS_PROVIDER_H
#include "drawableObject.h"
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
	vector<shared_ptr<Barnim::Hero>> getHeroes();
};

}; // namespace Barnim

Barnim::GameStatusProvider *getGameStatusProviderInstance();
#endif