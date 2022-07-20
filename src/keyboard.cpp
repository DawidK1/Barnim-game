#include "keyboard.h"

void Barnim::Keyboard::on_key_pressed(sf::Keyboard::Key key)
{
    for (auto handler : handlers)
    {
        if (handler.key == key)
        {
            handler.callback();
        }
    }
}
void Barnim::Keyboard::add_callback(void (*func)(), sf::Keyboard::Key key)
{
    Barnim::Keyboard::keyboardCallbackHandler handler = Barnim::Keyboard::keyboardCallbackHandler(func, key);
    handlers.push_back(handler);
}