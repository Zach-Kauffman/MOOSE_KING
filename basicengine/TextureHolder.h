#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class TextureHolder {
public:
    TextureHolder();
    void addTexture(std::string path, std::string name);
    sf::Texture& getTexture();
    std::vector<sf::Texture> textureList;
    std::vector<std::string> Map;

};


#endif //PLAYER_H
