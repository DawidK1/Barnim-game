#include "DrawableObject.h"

Barnim::DrawableObject::DrawableObject(DrawableObject &oldObj)
{
	this->texture = oldObj.texture;
	this->sprite = oldObj.sprite;

	this->position = oldObj.position;
	this->velocity = oldObj.velocity;
	this->size = oldObj.size;
	
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(position[0], position[1]));
}

void Barnim::DrawableObject::LoadTexture( std::string texturePath, float x, float y, float w, float h ) {
	if( !this->texture.loadFromFile( texturePath )) {
        std::cerr << "Nie udało się załadować pliku " << texturePath << std::endl;
	} else {
		texture.setSmooth( true );
		position = glm::vec2( x, y );
		size = glm::vec2( w, h );
		sprite.setPosition(sf::Vector2f(position[0], position[1]));
		sprite.setTexture(texture);
	}
}
sf::Sprite Barnim::DrawableObject::getTexture()
{
	sprite.setPosition(sf::Vector2f(position[0], position[1]));
	return sprite;
}
void Barnim::DrawableObject::update(float timeElapsed)
{
	move(timeElapsed);
}
void Barnim::DrawableObject::move(float timeElapsed)
{
	position+=velocity*timeElapsed;
}