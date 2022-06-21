#include "Control.h"
#include "hero.h"
int main(){
	Control app(false);
		app.addTexture("res/graphics/bg.png",0,0);
	app.addTexture("res/graphics/hero.png",100,100);
	app.addTexture("res/graphics/hero.png",200,200);
	app.addTexture("res/graphics/hero.png",300,300);
	app.addTexture("res/graphics/hero.png",400,400);
	Barnim::Hero Hero;
	app.run();
}