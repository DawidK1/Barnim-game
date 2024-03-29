#include "drawableObject.h"
#include "objectSpawner.h"

Barnim::DrawableObject::DrawableObject(DrawableObject &oldObj)
{
	this->texture = oldObj.texture;
	this->sprite = oldObj.sprite;

	this->position = oldObj.position;
	this->velocity = oldObj.velocity;
	this->size = oldObj.size;
	




	this->sprite.setTexture(this->texture);
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
sf::Drawable& Barnim::DrawableObject::getTexture()
{
	return sprite;
}
void Barnim::DrawableObject::update(float timeElapsed)
{
	move(timeElapsed);
	sprite.setPosition(sf::Vector2f(position[0], position[1]));
}
void Barnim::DrawableObject::move(float timeElapsed)
{
	position+=velocity*timeElapsed;
}

void Barnim::DrawableObject::remove()
	{
		auto spawner = Barnim::ObjectSpawner::getObjectSpawnerInstance();
		spawner->despawn(this);
	}