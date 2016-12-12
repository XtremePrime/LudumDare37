#include "player.h"

void Player::init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s)
{
	this->pos = p;
	this->size = s;
	this->texture = tx;
	this->dir = 1;
	this->actions = max_actions;

	//anims
	sprite_source = sf::IntRect(frame, 2, 16, 32);
	sprite.setTexture(texture);
	sprite.setTextureRect(sprite_source);
	sprite.setPosition(pos);
	sprite.scale(3,3);
	sprite.setOrigin(sf::Vector2f((s.x)/2.0f, (s.y)/2.0f));
	this->bbox = sprite.getGlobalBounds();

	this->left = this->right = false;

	//- skills
	skills.push_back(new Skill("Study"));
	skills.push_back(new Skill("Gaming"));
	skills.push_back(new Skill("Socializing"));

	this->name = "You";
}

void Player::move(sf::Time dt)
{
	if(left){
		if(dir == 1)
			sprite.scale(-1,1);
		dir = 0;
		pos.x -= speed * dt.asSeconds();
		moving = true;
	}
	else if(right){
		if(dir == 0)
			sprite.scale(-1,1);
		dir = 1;
		pos.x += speed * dt.asSeconds();
		moving = true;
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
	}
	else if(event.type == sf::Event::KeyReleased)
	{
		if(event.key.code == sf::Keyboard::A)
		{
			left = false;
			moving = false;
		}
		else if(event.key.code == sf::Keyboard::D)
		{
			right = false;
			moving = false;
		}
	}

}

void Player::update(sf::Time dt)
{
	// std::cout << (frame) << "\n";
	move(dt);
	// if(pos.x-(3*16)/2.0f < 0)
	// 	pos.x = 0-(3*16)/2.0f;
	// if(pos.x+(3*16)/2.0f > 640 )
	// 	pos.x = 640+(3*16)/2.0f;

	if(anim_clock.getElapsedTime().asSeconds() >= 0.15f && moving)
	{
		if(frame+1 > 4){
			frame = 1;
		}
		else{
			frame++;
		}
		sprite_source = sf::IntRect((frame)*16, 0*16, 16, 32);
		anim_clock.restart();
	}
	else if(moving == false){
		sprite_source = sf::IntRect(0*16, 0*16, 16, 32);
	}

	sprite.setTextureRect(sprite_source);
	sprite.setPosition(pos);
	this->bbox = sprite.getGlobalBounds();
	std::cout << "PLAYER: " << bbox.top << "," << bbox.left << "," << bbox.width << "," << bbox.height << "\n";
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void Player::check_status()
{
}
