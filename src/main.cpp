#include "Control.h"
#include "hero.h"
int main(){
	Control app(false);
	app.addTexture("res/graphics/bg.png",0,0);
	Barnim::Hero Hero;
	Hero.LoadTexture("res/graphics/hero.png",200,200,0,0);
	app.addDrawableObject(&Hero);
	app.run();
}