#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Platform {
public:
    Platform();
    void addPlatform(sf::Vector2f,sf::Vector2f,sf::Color);
    void drawPlatforms(sf::RenderWindow &);
    void findLocation(sf::RenderWindow &);
    void scrollPlatforms(float);
    std::vector<sf::RectangleShape> platformList;
    std::vector<sf::Vector2f> locationList;
private:
    sf::Color platColor;
    sf::Vector2f platSize;
    sf::Vector2f location;
};



#endif //PLATFORM_H
