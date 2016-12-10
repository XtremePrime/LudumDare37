#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "gamestate.h"

class MenuState : public State
{
private:
	sf::Font font;
	std::vector<std::string> options;
	int width, height, selector;
	bool newgame;
	sf::Text option_text;
protected:
	static MenuState* _instance;
	MenuState(){}
public:
	static MenuState* instance();
    ~MenuState(){}
	void init(Game* game);
	void cleanup();

	void handle_events(Game* game, sf::Event event);
	void update(Game* game, sf::Time deltaTime);
	void render(Game* game);

 	void pause();
 	void resume();

 	template<typename T>
 	void clear_vector(std::vector<T*>& v)
 	{
 		for(int i = 0; i < v.size(); ++i)
 			delete (v[i]);
 		v.clear();
 	}
};

#endif // MENUSTATE_H