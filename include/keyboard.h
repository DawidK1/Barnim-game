#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "DrawableObject.h"
#include <SFML/Window.hpp>
#include <vector>
namespace Barnim
{
	class Keyboard
	{
		private:
		class keyboardCallbackHandler
		{
			public:
			void (*callback)();
			sf::Keyboard::Key key;
			keyboardCallbackHandler(void (*func)(),sf::Keyboard::Key key){this->key=key; callback=func;}
			keyboardCallbackHandler(const keyboardCallbackHandler& old){key=old.key; callback=old.callback;}
		};
		std::vector<Barnim::Keyboard::keyboardCallbackHandler> handlers;
		public:
		void add_callback(void (*func)(),sf::Keyboard::Key key);
		void on_key_pressed(sf::Keyboard::Key key);
	};
};
#endif