#include "player.h"

void Player::init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s)
{
	this->pos = p;
	this->size = s;
	this->tx = tx;

	sprite.setTexture(tx);
	sprite.setPosition(p);
}

void Player::handle_events(sf::Event event)
{

}

void Player::update(sf::Time deltaTime)
{

}

void Player::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}
