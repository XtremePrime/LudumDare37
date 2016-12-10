#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../texturemanager.h"
#include "../entities/player.h"
#include <SFML/Graphics.hpp>

class GameState : public State
{
private:
	Player player;
	TextureManager tx;
	std::map<std::string, sf::Sprite> sprites;
protected:
	static GameState* _instance;
	GameState(){}
public:
	static GameState* instance();
    ~GameState(){}
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

#endif // GAMESTATE_H
