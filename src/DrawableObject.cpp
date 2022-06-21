#include "DrawableObject.h"

void Barnim::DrawableObject::LoadTexture( std::string texturePath, float x, float y, float w, float h ) {
	if( !this->texture.loadFromFile( texturePath )) {
        std::cerr << "Nie udało się załadować pliku " << texturePath << std::endl;
	} else {
		texture.setSmooth( true );
		position = glm::vec2( x, y );
		size = glm::vec2( w, h );
	}
}
