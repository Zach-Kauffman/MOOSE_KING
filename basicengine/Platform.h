#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Platform {
public:
    Platform();
    sf::RectangleShape createPlatform(sf::Vector2f,sf::Vector2f,sf::Color);
    void addPlatform(sf::Vector2f,sf::Vector2f,sf::Color);
    void drawPlatforms(sf::RenderWindow &);
    void scrollPlatforms(sf::Vector2f);
    std::vector<sf::RectangleShape> platformList;
private:
    sf::Color platColor;
    sf::Vector2f platSize;
    sf::Vector2f location;
};



#endif //PLATFORM_H
