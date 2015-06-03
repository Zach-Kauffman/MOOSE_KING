#include "Platform.h"
#include "Player.h"


using namespace std;

Platform::Platform() {
    location.x = 0;
    location.y = 0;
}

sf::RectangleShape Platform::createPlatform(sf::Vector2f platSize,sf::Vector2f location,sf::Color color) {
    sf::RectangleShape temp;

    return temp;
}

void Platform::addPlatform(sf::Vector2f platSize,sf::Vector2f location,sf::Color color) {
    sf::RectangleShape temp;
    temp.setSize(platSize);
    temp.setPosition(location);
    temp.setFillColor(color);
    platformList.push_back(temp);
}

void Platform::drawPlatforms(sf::RenderWindow &Window) {
    for (int ii = 0; ii < platformList.size(); ii ++) {
        Window.draw(platformList[ii]);
    }
}


