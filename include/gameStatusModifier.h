#ifndef GAME_STATUS_MODIFIER_H
#define GAME_STATUS_MODIFIER_H
#include "drawableObject.h"
#include "control.h"
#include "hero.h"
#include "enemy.h"
#include "text.h"
using namespace std;
namespace Barnim
{
	
class GameStatusModifier
{
  private:
	Control *controlPtr;
	std::shared_ptr<Barnim::Text> pauseText;
  public:
	GameStatusModifier();
	void attachGameControl(Control *control);
	void pauseGame();
    void resumeGame();
	void togglePause();
};

}; // namespace Barnim

Barnim::GameStatusModifier *getGameStatusModifierInstance();
#endif