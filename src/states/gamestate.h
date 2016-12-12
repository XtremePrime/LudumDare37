#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"
#include "../texturemanager.h"
#include "../entities/player.h"
#include <SFML/Graphics.hpp>
#include "../event.hpp"
#include "../entities/entity.h"
#include "../entities/hotspot.hpp"
#include <sstream>
#include "../sound.hpp"
#include "endstate.h"

class GameState : public State
{
private:
	Player player;
	TextureManager tx;
	std::map<std::string, sf::Sprite> sprites;
	std::vector<Event*> events;
	std::vector<Hotspot*> hotspots;
	sf::Font font;
	sf::Text day_text, pts_text;
	Sound action_snd;
	Sound sleep_snd;
	sf::Music music;

	sf::Texture bg_tx;
	sf::Sprite bg;
	sf::Sprite action_btn;

	int day;
	bool show = false;
	int loc = -1;
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

 	//- Day related
 	void advance_day();
 	int get_day(){return this->day;}
 	void set_day(int d){this->day = d;}
 	void check_for_events(int d);

 	template<typename T>
 	void clear_vector(std::vector<T*>& v)
 	{
 		for(int i = 0; i < v.size(); ++i)
 			delete (v[i]);
 		v.clear();
 	}
};

#endif // GAMESTATE_H
