#include "menustate.h"

MenuState* MenuState::_instance;
MenuState* MenuState::instance(){
	if(_instance == NULL)
		_instance = new MenuState();
	return _instance;
}

void MenuState::init(Game* game)
{
	this->width = game->get_width();
	this->height = game->get_height();

	// TODO: ng based on save
	this->newgame = true;
	this->selector = 0;

	if(newgame)
		options.push_back("New Game");
	else
		options.push_back("Continue");

	this->font.loadFromFile("res/font/PressStart2P.ttf");

	option_text.setCharacterSize(20);
	option_text.setFont(font);
	option_text.setPosition(30, height-90);
	option_text.setColor(sf::Color::White);
	{
		std::string msg;
		for(int i = 0; i < options.size(); ++i){
			msg += options[i] + "\n\n";
		}
		option_text.setString(msg);
	}

	tx.loadFromFile("res/screens/intro.png");
	sprite.setTexture(tx);
	sprite.setPosition(0,-10);
	sprite.scale(0.7,0.7);
}

void MenuState::cleanup()
{

}

void MenuState::handle_events(Game* game, sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::W)
		{
			if(selector-1 < 0)
				selector = options.size()-1;
			else
				selector--;
		}
		else if(event.key.code == sf::Keyboard::S)
		{
			if(selector+1 > options.size()-1)
				selector = 0;
			else
				selector++;
		}

		if(event.key.code == sf::Keyboard::Return)
		{
			switch(selector)
			{
				case 0:
					game->change_state(GameState::instance());
				break;
				case 1:
					game->quit();
				break;
			}
		}
	}
}

void MenuState::update(Game* game, sf::Time deltaTime)
{
	std::cout << selector << "\n";
}

void MenuState::render(Game* game)
{
	game->get_window()->draw(sprite);
	game->get_window()->draw(option_text);
}

void MenuState::pause()
{

}

void MenuState::resume()
{

}
