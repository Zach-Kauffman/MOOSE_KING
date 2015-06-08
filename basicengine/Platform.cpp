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
    temp.setOrigin(0,0);
    platformList.push_back(temp);
}

void Platform::drawPlatforms(sf::RenderWindow &Window) {
    for (int ii = 0; ii < platformList.size(); ii ++) {
        Window.draw(platformList[ii]);
    }
}

void Platform::scrollPlatforms(sf::Vector2f position) {
    for (int ii = 0; ii < platformList.size(); ii ++) {
        platformList[ii].setPosition(sf::Vector2f(platformList[ii].getPosition().x + position.x,platformList[ii].getPosition().y + position.y));
    }
}


