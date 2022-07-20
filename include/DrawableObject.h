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
			float movementValue=3;
		public:
			DrawableObject(){};
			~DrawableObject(){};
			void LoadTexture( std::string texturePath, float x, float y, float w, float h );
			virtual sf::Sprite getTexture();
			glm::vec2 getPos(){ return position; };
			glm::vec2 getCoords(){ return texCoords; };
			int getMovementValue(){return movementValue;};
			void movement(int options);
			void increaseSpeed();
			void decreaseSpeed();
			int UP=0;
			int DOWN=1;
			int RIGHT=2;
			int LEFT=3;
	};
};
#endif