#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>

class Flashlight {
public:
    Flashlight();
    void squareGenerator(sf::RenderWindow&,sf::Clock&);
    void game(sf::RenderWindow&,sf::Clock&);
    void variable(sf::RenderWindow&);
    void time(sf::RenderWindow&,sf::Clock&);
    void restart(sf::RenderWindow&);
    bool win;
private:
    sf::CircleShape mouse;
    sf::Sprite background;
    sf::Sprite light;
    sf::Sprite Moose;
    sf::Texture light1;
    sf::Texture light2;
    sf::Texture light3;
    sf::Texture light4;
    sf::Texture light5;
    sf::Texture light6;
    sf::Texture forest;
    sf::Texture moosetexture;
    sf::Text timer;
    sf::Text restartprompt;
    sf::Text wintext,losetext;
    sf::Font font;
    std::string timestring;
    float squarex, squarey, mousex, mousey;
    int level, found, countdown;

};

#endif // FLASHLIGHT_H
