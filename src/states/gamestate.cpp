#include "gamestate.h"

GameState* GameState::_instance;
GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init(Game* game)
{
	tx.load_sheet("res/ss.png");
	tx.load_texture("bed", 0, 0, 3, 2);
	tx.load_texture("desk", 3, 0, 2, 2);
	tx.load_texture("fridge", 5, 0, 1, 2);

	tx.load_texture("player", 6, 2, 3, 2);

	sprites["bed"].setTexture(tx.get_ref("bed"));
	sprites["bed"].setOrigin(0, (2*16));
	sprites["bed"].setPosition(200, 100);
	sprites["bed"].scale(2.5f, 2.5f);

	sprites["desk"].setTexture(tx.get_ref("desk"));
	sprites["desk"].setOrigin((2*16)/2.0f, (2*16)/2.0f);
	sprites["desk"].setPosition(300, 100);
	sprites["desk"].scale(3.f, 3.f);

	player.init(tx.get_ref("player"), sf::Vector2f(100, 100), sf::Vector2i(16, 32));
}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{
	player.handle_events(event);
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	player.update(deltaTime);
}

void GameState::render(Game* game)
{
	//- Render sprites
	#define it_type std::map<std::string, sf::Sprite>::iterator
	for(it_type it = sprites.begin(); it != sprites.end(); ++it)
		game->get_window()->draw(it->second);
	#undef it_type

	player.render(game->get_window());
}

void GameState::pause()
{

}

void GameState::resume()
{

}
