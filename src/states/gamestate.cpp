#include "gamestate.h"

GameState* GameState::_instance;
GameState* GameState::instance(){
	if(_instance == NULL)
		_instance = new GameState();
	return _instance;
}

void GameState::init(Game* game)
{
	tx.load_sheet("res/ss2.png");
	tx.load_texture("flower1", 0, 0, 1, 1);
	tx.load_texture("flower2", 1, 0, 1, 1);

	// sprites["flower1"].setTexture(tx.get_ref("flower1"));
	// sprites["flower1"].setPosition(game->get_width()/2, game->get_height()/2);
	// sprites["flower1"].scale(3, 3);

	player.init(tx.get_ref("flower1"), sf::Vector2f(100, 100), sf::Vector2i(16, 16));
}

void GameState::cleanup()
{

}

void GameState::handle_events(Game* game, sf::Event event)
{

}

void GameState::update(Game* game, sf::Time deltaTime)
{

}

void GameState::render(Game* game)
{
	player.render(game->get_window());

	//- Render sprites
	#define it_type std::map<std::string, sf::Sprite>::iterator
	for(it_type it = sprites.begin(); it != sprites.end(); ++it)
		game->get_window()->draw(it->second);
	#undef it_type
}

void GameState::pause()
{

}

void GameState::resume()
{

}
