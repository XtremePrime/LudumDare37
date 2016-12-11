#include "player.h"

void Player::init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s)
{
	this->pos = p;
	this->size = s;
	this->tx = tx;
	this->dir = 1;

	sprite_source = sf::IntRect(frame, 2, 16, 32);
	sprite.setTexture(tx);
	sprite.setTextureRect(sprite_source);
	sprite.setPosition(p);
	sprite.setOrigin(sf::Vector2f(16/2, 32/2));
	sprite.scale(3,3);

	this->left = this->right = false;
}

void Player::move(sf::Time dt)
{
	if(left){
		if(dir == 1)
			sprite.scale(-1,1);
		dir = 0;
		pos.x -= speed * dt.asSeconds();
	}
	else if(right){
		if(dir == 0)
			sprite.scale(-1,1);
		dir = 1;
		pos.x += speed * dt.asSeconds();
	}
}

void Player::handle_events(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::A)
		{
			left = true;
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			right = true;
		}

		if(event.key.code == sf::Keyboard::D)
		{
			right = true;
		}
	}
	else if(event.type == sf::Event::KeyReleased)
	{
		if(event.key.code == sf::Keyboard::A)
		{
			left = false;
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			right = false;
		}
	}

}

void Player::update(sf::Time dt)
{
	std::cout << (frame) << "\n";
	move(dt);

	if(anim_clock.getElapsedTime().asSeconds() >= 0.15f)
	{
		if(frame+1 > 2){
			frame = 0;
		}
		else{
			frame++;
		}
		sprite_source = sf::IntRect((frame)*16, 0*16, 16, 32);
		anim_clock.restart();
	}

	sprite.setTextureRect(sprite_source);
	sprite.setPosition(pos);
	this->bbox = sprite.getGlobalBounds();
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}
