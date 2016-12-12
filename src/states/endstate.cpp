#include "endstate.h"

EndState* EndState::_instance;
EndState* EndState::instance(){
	if(_instance == NULL)
		_instance = new EndState();
	return _instance;
}

void EndState::init(Game* game)
{
	this->width = game->get_width();
	this->height = game->get_height();

	tx.loadFromFile("res/screens/ending.png");
	sprite.setTexture(tx);
	sprite.setPosition(-15,-10);
	sprite.scale(0.7,0.7);

	// option_text.setCharacterSize(20);
	// option_text.setFont(font);
	// option_text.setPosition(30, height-90);
	// option_text.setColor(sf::Color::White);
}

void EndState::cleanup()
{

}

void EndState::handle_events(Game* game, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Return)
		{
			game->quit();
		}
	}
}

void EndState::update(Game* game, sf::Time deltaTime)
{

}

void EndState::render(Game* game)
{
	game->get_window()->draw(sprite);
}

void EndState::pause()
{

}

void EndState::resume()
{

}
