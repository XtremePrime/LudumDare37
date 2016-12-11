#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Player
{
private:
	sf::Vector2f pos;
	sf::Vector2i size;
	sf::Texture tx;
	sf::Sprite sprite;
	int dir;
	float speed = 100.0f;
	bool left, right;
	sf::FloatRect bbox;

	bool moved = false;
	sf::Clock anim_clock;
	sf::IntRect sprite_source;
	int offset = 4;
	int frame = 0;

	int actions = 10, max_actions = 10;

	std::vector<int> skills;
public:
	void init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s);
	void move(sf::Time);
	void handle_events(sf::Event);
	void update(sf::Time);
	void render(sf::RenderWindow*);

	void set_sprite(sf::Texture& tx){this->tx = tx; this->sprite.setTexture(tx);}
};

#endif // PLAYER_H