#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "texturemanager.h"

// void TextureManager::load_texture(const std::string& name, const std::string& path)
// {
// 	sf::Texture tx;
// 	tx.loadFromFile(path);

// 	textures[name] = tx;
// }

void TextureManager::load_sheet(const std::string& path)
{
	spritesheet.loadFromFile(path);
}

void TextureManager::load_texture(const std::string& name, int x, int y, int w, int h)
{
	sf::Texture tx;
	tx.loadFromImage(spritesheet, sf::IntRect(x*16, y*16, w*16, h*16));

	textures[name] = tx;
}

sf::Texture& TextureManager::get_ref(const std::string& texture)
{
	return this->textures.at(texture);
}