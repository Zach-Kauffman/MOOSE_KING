#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Platform {
private:
    Platform();
public:
    int length;
    sf::Vector2f location;
};



#endif //PLATFORM_H
