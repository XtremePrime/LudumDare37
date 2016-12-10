#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Vector2f pos;
	sf::Vector2i size;
	sf::Texture tx;
	sf::Sprite sprite;
public:
	void init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s);
	void handle_events(sf::Event);
	void update(sf::Time);
	void render(sf::RenderWindow*);
};

#endif // PLAYER_H