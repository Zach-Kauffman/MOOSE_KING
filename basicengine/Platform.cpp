#include "Platform.h"
#include "Player.h"


using namespace std;

Platform::Platform() {
    location.x = 0;
    location.y = 0;
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
        location = platformList[ii].getPosition();
    }
}

void Platform::findLocation(sf::RenderWindow &Window) {
    for (int ii = 0; ii < platformList.size(); ii ++) {
        locationList.push_back(platformList[ii].getPosition());
    }
}

void Platform::scrollPlatforms(float bgX) {
    for (int ii = 0; ii < platformList.size(); ii ++) {
        platformList[ii].setPosition(locationList[ii].x + bgX, locationList[ii].y);
    }
}


