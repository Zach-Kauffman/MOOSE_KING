#ifndef PONG_H
#define PONG_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>

class Pong {
public:
    Pong();
    void game(sf::RenderWindow&);
    void variable(sf::RenderWindow&);
    void restart(sf::RenderWindow&);
    void shake(sf::RenderWindow&);
    sf::Sprite bg;
    sf::Texture bgTexture;
    sf::RectangleShape player1,player2,barrier1,barrier2,scoreboard;
    sf::CircleShape ball;
    sf::Font font;
    sf::Text score1, score2, title;
    std::string score1string, score2string;
    float x, y, p1x, p1y, p2x, p2y;
    float b1x, b1y, b2x, b2y, scoreboardx, scoreboardy, xspeed, yspeed;
    bool right, up;
    int paddlehits, counter, temp1, temp2;
    float g, r;
    float startingspeed, p1score, p2score;
    std::string titleText;
};

#endif // PONG_H
