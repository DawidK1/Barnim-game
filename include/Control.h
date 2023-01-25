#ifndef CONTROL_H
#define CONTROL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "DrawableObject.h"
#include "keyboard.h"
#include <memory>
#include <string>
using namespace std;
class Control
{
  private:
    vector<sf::Texture> textures;
    vector<sf::Sprite> sprites;
    vector < shared_ptr<Barnim::DrawableObject> > objects;
    bool isGamePaused=false;
  public:
    Barnim::Keyboard keyboard;
    sf::RenderWindow window;
    unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height},
                 screen[2] = {800, 600};
    bool fullscreen;
    string title = "Barnim";
    sf::Time time, game_time;
    sf::Clock clock, game_clock;

    Control(bool);
    void output();
    void center_window();
    void events(sf::Event);
    void time_update();
    void update(float timeElapsed);
    void render();
    void run();
    void addTexture(std::string filename, int x, int y);
    void addDrawableObject(shared_ptr<Barnim::DrawableObject> object);
    void removeDrawableObject(Barnim::DrawableObject * objectToRemove);
    vector<shared_ptr<Barnim::DrawableObject>> getAllObjects() { return objects; };
    void pauseGame();
    void resumeGame();
    void togglePause();
    void showText(string text, int posX, int poY);
};
#endif