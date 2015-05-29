#include "Platform.h"


using namespace std;

Platform::Platform() {
    location.x = 0;
    location.y = 0;
}

sf::RectangleShape Platform::createPlatform(sf::Vector2f platSize,sf::Vector2f location) {
    sf::RectangleShape temp;
    temp.setSize(platSize);
    temp.setPosition(location);
    return temp;
}

void Platform::addPlatform(sf::RectangleShape temp) {
    platformList.push_back(temp);
}
