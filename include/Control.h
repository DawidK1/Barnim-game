#ifndef CONTROL_H
#define CONTROL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "DrawableObject.h"
#include "keyboard.h"
class Control{
    private:
        std::vector<sf::Texture> textures;
        std::vector<sf::Sprite> sprites;
        std::vector<Barnim::DrawableObject*> objects;

    public:
        Barnim::Keyboard keyboard;
        sf::RenderWindow window;
        unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height},
            screen[2] = {800,600};
        bool fullscreen;
        std::string title = "Barnim";
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
        void addTexture(char *filename, int x, int y);
        void addDrawableObject(Barnim::DrawableObject *object);
        std::vector<Barnim::DrawableObject*> getAllObjects() {return objects;};
};   
#endif