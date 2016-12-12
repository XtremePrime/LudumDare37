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
	tx.load_texture("door", 5, 0, 1, 2);
	tx.load_texture("action_btn", 0, 4, 1, 1);
	tx.load_texture("player", 4, 2, 5, 2);

	sprites["bed"].setTexture(tx.get_ref("bed"));
	sprites["bed"].setOrigin(0, 2*16);
	sprites["bed"].setPosition(10, game->get_height()/2.0f);
	sprites["bed"].scale(2.5f, 2.5f);

	sprites["desk"].setTexture(tx.get_ref("desk"));
	sprites["desk"].setOrigin(0, (2*16));
	sprites["desk"].setPosition(150, game->get_height()/2.0f);
	sprites["desk"].scale(3.f, 3.f);

	sprites["door"].setTexture(tx.get_ref("door"));
	sprites["door"].setOrigin(0, (2*16));
	sprites["door"].setPosition(300, game->get_height()/2.0f);
	sprites["door"].scale(3.f, 3.f);

	action_btn.setTexture(tx.get_ref("action_btn"));
	action_btn.setOrigin(16/2.0f, 16/2.0f);
	action_btn.setPosition(20, 20);
	action_btn.scale(1.5f, 1.5f);

	this->font.loadFromFile("res/font/PressStart2P.ttf");
	day_text.setCharacterSize(11);
	day_text.setFont(font);
	day_text.setPosition(10, 10);
	day_text.setColor(sf::Color::White);
	day_text.setString("Day: 1");

	pts_text.setCharacterSize(11);
	pts_text.setFont(font);
	pts_text.setPosition(game->get_width()-80,10);
	pts_text.setColor(sf::Color::White);
	pts_text.setString("10/10");

	player.init(tx.get_ref("player"), sf::Vector2f(100, (game->get_height()/2.0f)-(32*3)/2 ), sf::Vector2i(16, 32));

	//- Events
	events.push_back(new Event(1, Mode::FIXED_DAY));

	//- hotspots
	hotspots.push_back(new Hotspot(10, (game->get_height()/2.0f)-32*3, 48*2.5f, 32*2.5f, sf::Color(255, 0, 0, 255))); // Sleep
	hotspots.push_back(new Hotspot(150, (game->get_height()/2.0f)-32*3, 16*2, 32, sf::Color(255, 255, 0, 255))); // Study
	hotspots.push_back(new Hotspot(200, (game->get_height()/2.0f)-32*3, 16*3, 32, sf::Color(255, 255, 0, 255))); // Game
	hotspots.push_back(new Hotspot(300, (game->get_height()/2.0f)-32*3, 16*3, 32*3, sf::Color(255, 255, 0, 255))); // socialize

	//- Background
	bg_tx.loadFromFile("res/screens/game.png");
	bg.setTexture(bg_tx);
	bg.setPosition(0,-10);
	bg.scale(0.7,0.7);

	//-
	this->day = 1;
	this->loc = 0;
	//Hotspot at 0,4 in ss

	action_snd.load("res/sfx/act.wav");
	sleep_snd.load("res/sfx/wakeup.wav");
	music.openFromFile("res/sfx/music-POL.wav");
	music.play();
	music.setLoop(true);
	music.setVolume(50);
}

void GameState::cleanup()
{

}

void GameState::advance_day()
{
	day++;
	player.reset_actions();
	check_for_events(day);
	{
		std::stringstream ss;
		ss << "Day: " << day;
		day_text.setString(ss.str());
	}
}

void GameState::check_for_events(int d){}

void GameState::handle_events(Game* game, sf::Event event)
{
	player.handle_events(event);

	if(event.type == sf::Event::KeyPressed)
	{
		if(event.key.code == sf::Keyboard::Space)
		{
			//- Sleep
			if(loc == 0){
				advance_day();
				sleep_snd.play();
				if(day > 10)
				{
					game->change_state(EndState::instance());
				}
			}else if(loc == 1 && player.get_actions() > 0){ //- Study
				player.get_skill(0)->add_pts(1);
				player.act(1);
				action_snd.play();
			}else if(loc == 2 && player.get_actions() > 0){ //- Gaming
				player.get_skill(1)->add_pts(1);
				player.act(1);
				action_snd.play();
			}else if(loc == 3 && player.get_actions() > 0){ //- Socializing
				player.get_skill(2)->add_pts(1);
				player.act(1);
				action_snd.play();
			}
		}
	}
}

void GameState::update(Game* game, sf::Time deltaTime)
{
	std::cout << "show: " << show << "\n";
	for(int i = 0; i < hotspots.size(); ++i){
		show = false;
		loc = -1;
		// std::cout << "h: " << h->get_bbox().top << " , " << player.get_bbox().top << " | " << player.intersects(h) << "\n";
		if(player.intersects(hotspots[i])){
			std::cout << "Happening!\n";
			action_btn.setPosition(hotspots[i]->get_btn_pos().x, hotspots[i]->get_btn_pos().y);
			loc = i;
			show = true;
			break;
		}
	}

	player.update(deltaTime);
	{
		std::stringstream ss;
		ss << player.get_actions() << "/" << player.get_max_actions();
		pts_text.setString(ss.str());
	}
}

void GameState::render(Game* game)
{
	game->get_window()->draw(bg);

	// for(Hotspot* h : hotspots)
	// 	h->render(game->get_window());

	//- Render sprites
	#define it_type std::map<std::string, sf::Sprite>::iterator
	for(it_type it = sprites.begin(); it != sprites.end(); ++it)
		game->get_window()->draw(it->second);
	#undef it_type

	if(show == true){
		std::cout << "what are you, a fucking faggot?\n";
		game->get_window()->draw(action_btn);
	}



	player.render(game->get_window());


	game->get_window()->draw(day_text);
	game->get_window()->draw(pts_text);
}

void GameState::pause()
{

}

void GameState::resume()
{

}
