#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Platform {
private:
    Platform();
    sf::RectangleShape createPlatform(sf::Vector2f,sf::Vector2f);
    void addPlatform(sf::RectangleShape);
public:
    std::vector<sf::RectangleShape> platformList;
    sf::Vector2f platSize;
    sf::Vector2f location;
};



#endif //PLATFORM_H
