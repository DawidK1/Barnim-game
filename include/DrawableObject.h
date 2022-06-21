#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include<string>
#include<glm/glm.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
namespace Barnim {
	class DrawableObject {
		protected:
			sf::Texture texture;
			sf::Sprite sprite;
			glm::vec2 position;
			glm::vec2 size;
			glm::vec2 texCoords;
		public:
			DrawableObject(){};
			~DrawableObject();
			void LoadTexture( std::string texturePath, float x, float y, float w, float h );
			virtual sf::Texture getTexture();
	};
};
#endif