#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>

#include "gameobject.h"
#include "pugixml.hpp"

class State;
class Game
{
private:
	sf::RenderWindow window;
	const int GAME_WIDTH = 640, GAME_HEIGHT = 480;
	const float SCALE = 1.5f;
	bool is_running = true;
	sf::Clock clock;
	std::vector<State*> state_stack;
	sf::Image icon;
	GameObject gameobject;
	sf::ContextSettings settings;
	sf::View view;
	sf::Music music;
	// SaveFile savefile;

	void init();
	void update(sf::Time);
	void handle_events(sf::Event);
	void render(sf::RenderWindow&);
public:
	void change_state(State* state);
	void push_state(State* state);
	void pop_state();

	void run();
	void quit();

	sf::RenderWindow* get_window() { return &window; }
	GameObject* get_gameobject() { return &gameobject; }
	std::vector<State*> get_state_stack() { return state_stack; }
	float get_width() { return this->GAME_WIDTH/this->SCALE; }
	float get_height() { return this->GAME_HEIGHT/this->SCALE; }
	float get_scale(){ return this->SCALE; }
	//SaveFile& get_save() { return this->savefile; }
};

#endif // GAME_H
