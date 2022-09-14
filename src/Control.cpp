
#include "Control.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


Control::Control(bool scr) : fullscreen(scr)
{
	time = sf::seconds(0);
	if (fullscreen)
		window.create(sf::VideoMode(monitor[0], monitor[1]), title, sf::Style::Fullscreen);
	else
	{
		window.create(sf::VideoMode(screen[0], screen[1]), title);
		center_window();
	}
	textures.reserve(1000);
}

void Control::center_window()
{
	window.setPosition(
		sf::Vector2i(
			(monitor[0] / 2) - (screen[0] / 2),
			(monitor[1] / 2) - (screen[1] / 2)));
}

void Control::events(sf::Event e)
{
	while (window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			keyboard.on_key_pressed(e.key.code);
		}
	}
}

void Control::update(float timeElapsed)
{
	for (auto Objectptr:objects)
	{
		Objectptr->update(timeElapsed);
	}
}

void Control::render()
{
	//sf::Sprite sprite;
	//glm::vec2 position; 
	window.clear();

	for(auto sprite:sprites)
	{
		window.draw(sprite);
	}
	for (auto Objectptr:objects)
	{
		//sprite=Objectptr->getTexture();

		//sprite.setPosition(sf::Vector2f(position.x, position.y));
		window.draw(Objectptr->getTexture());
	}
	
	window.display();
}

void Control::run()
{
	sf::Clock clock;
	float timeElapsed;
	while (window.isOpen())
	{
		timeElapsed=clock.getElapsedTime().asSeconds();
		clock.restart();
		sf::Event event;
		events(event);
		update(timeElapsed);//TODO znalesc czas jaki uplyna od ostatniej ramki
		render();
	}
}

void Control::addTexture(char *filename, int x, int y)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filename))
	{
		std::cout<<"error loading texture";
		while(1);
	}
	textures.push_back(texture);
	sf::Sprite sprite;
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setTexture(textures[textures.size()-1]);
	sprites.push_back(sprite);
}
void Control::addDrawableObject(Barnim::DrawableObject *object)
{
	objects.push_back(object);
}