#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


class TextureHolder {
public:
    TextureHolder();
    void addTexture(std::string path, std::string name);
    sf::Texture* getTexture(std::string name);
    sf::Texture& getTextureRef(std::string name);
    std::vector<sf::Texture> textureList;
    std::map<std::string, int> textureMap;

};


#endif //TEXTUREHOLDER_H
