#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include<string>
#include<glm/glm.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include "util.h"
namespace Barnim {
	class DrawableObject {
		protected:
			sf::Texture texture;
			sf::Sprite sprite;
			glm::vec2 position;
			glm::vec2 velocity;
			glm::vec2 size;
		public:
			DrawableObject(){};
			DrawableObject(DrawableObject & oldObj);
			~DrawableObject(){std::cout<<"drawableObj destructor"<<std::endl;};
			void LoadTexture( std::string texturePath, float x, float y, float w, float h );
			virtual sf::Sprite getTexture();
			glm::vec2 getPos(){ return position; };
			virtual void update(float timeElapsed);
			virtual void move(float timeElapsed);
			void remove();
	};
};
#endif