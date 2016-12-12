#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../skill.hpp"
#include "entity.h"
#include "hotspot.hpp"

class Player : public Entity
{
private:
	sf::Vector2f pos;
	sf::Vector2i size;
	int dir;
	float speed = 150.0f;
	bool left, right;

	sf::Clock anim_clock;
	sf::IntRect sprite_source;
	int offset = 4;
	int frame = 0;
	bool moving = false;

	int max_actions = 10, actions;

	std::vector<Skill*> skills;
public:
	void init(sf::Texture& tx, sf::Vector2f p, sf::Vector2i s);
	void move(sf::Time);
	void handle_events(sf::Event);
	void update(sf::Time);
	void render(sf::RenderWindow*);

	void check_status();

	void set_sprite(sf::Texture& tx){this->texture = tx; this->sprite.setTexture(tx);}
	int get_actions(){return this->actions;}
	void act(int am=1){actions-=am; if(actions < 0) actions = 0;}
	int get_max_actions(){return this->max_actions;}
	void reset_actions(){this->actions = max_actions;}
	Skill* get_skill(int x){return skills[x];}

	bool intersects(Hotspot* h){
        return bbox.intersects(h->get_bbox());
    }
};

#endif // PLAYER_H
