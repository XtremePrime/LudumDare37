#ifndef HOTSPOT_HPP
#define HOTSPOT_HPP

#include "entity.h"
#include <SFML/Graphics.hpp>

class Hotspot : public Entity
{
private:
	sf::Vector2i pos;
	sf::Vector2i size;
	sf::RectangleShape rect;
public:
	Hotspot(int x, int y, int w, int h, sf::Color col){
		init(x,y,w,h,col);
	}

	void init(int x, int y, int w, int h, sf::Color col){
		this->pos = sf::Vector2i(x, y);
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;

		rect.setSize(sf::Vector2f(w, h));
		rect.setOutlineColor(col);
		rect.setOutlineThickness(3);
		rect.setPosition(x, y);

		this->bbox = rect.getGlobalBounds();
	}

	sf::Vector2i get_btn_pos(){return sf::Vector2i(x+(w/2)-(16/2), y-16-10);}
	void update(sf::Time deltaTime){this->bbox = sprite.getGlobalBounds();}
	void handle_events(sf::Event ev){}
	void render(sf::RenderWindow* win){
		win->draw(rect);
	}

	sf::Vector2i get_pos(){return this->pos;}
};

#endif // HOTSPOT_HPP
