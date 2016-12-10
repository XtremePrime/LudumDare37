#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager{
private:
	std::map<std::string, sf::Texture> textures;
	sf::Image spritesheet;
protected:
public:
	TextureManager(){}
	~TextureManager(){}

	void load_sheet(const std::string&);
	// void load_texture(const std::string&, const std::string&);
	void load_texture(const std::string&, int x, int y, int w, int h);
	sf::Texture& get_ref(const std::string&);
};

#endif // TEXTUREMANAGER_H