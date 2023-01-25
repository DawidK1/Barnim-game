#ifndef GAME_STATUS_MODIFIER_H
#define GAME_STATUS_MODIFIER_H
#include "drawableObject.h"
#include "control.h"
#include "hero.h"
#include "enemy.h"
using namespace std;
namespace Barnim
{
	
class GameStatusModifier
{
  private:
	Control *controlPtr;

  public:
	GameStatusModifier() { controlPtr = NULL; };
	void attachGameControl(Control *control);
	void pauseGame();
    void resumeGame();
};

}; // namespace Barnim

Barnim::GameStatusModifier *getGameStatusModifierInstance();
#endif