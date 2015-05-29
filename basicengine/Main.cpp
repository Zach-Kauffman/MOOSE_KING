#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <vector>
#include "Pong.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Flashlight.h"

using namespace std;

bool pongGame() {
    int side = 0;
    Pong p;
    if (!p.font.loadFromFile("alba.TTF")) {
        cout << "FONT FAILED TO LOAD";
    }
    sf::RenderWindow pongWindow(sf::VideoMode(1024, 768), "The Game");
    pongWindow.setFramerateLimit(9999);
    p.variable(pongWindow);
    while (pongWindow.isOpen()) {
        pongWindow.clear(sf::Color(0,102,0));
        p.game(pongWindow);
        pongWindow.display();
        if (p.p1score >= 7) {
            pongWindow.close();
            cout << "You won!";
            return true;
        }
        if (p.p2score >= 7) {
            pongWindow.close();
            cout << "You lose!";
            return false;
        }
    }
}

bool flashlightGame() {
    srand(time(NULL));
    Flashlight F;
    sf::RenderWindow flashlightWindow(sf::VideoMode(1020,764), "HIDE");
    sf::Clock clock;

    F.squareGenerator(flashlightWindow,clock);
    while(flashlightWindow.isOpen())
    {
        flashlightWindow.clear(sf::Color::Blue);
        F.variable(flashlightWindow);
        F.game(flashlightWindow,clock);
        F.time(flashlightWindow,clock);
        flashlightWindow.display();
    }
    if (F.win == true) {
        return true;
    }
    if (F.win == false) {
        return false;
    }
}

int main()
{
    srand(time(NULL));
    float acceleration;
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "Sprite Sheet");
    Window.setFramerateLimit(18);

    Window.setKeyRepeatEnabled(false);
    TextureHolder TempTextureHolder;
    Player Moose(TempTextureHolder);

    sf::Texture backg;
    sf::Sprite background;

    sf::RectangleShape platform (sf::Vector2f(500,340));
    platform.setSize(sf::Vector2f(1280,32));
    platform.setPosition(500,340);

    if(!backg.loadFromFile("scrollingtest.png")) {
        std::cout << "ERROR" << std::endl;
    }

    Moose.MooseSprite.setPosition(500,325);


    Moose.Animate();
    background.setTexture(backg);
    background.setPosition(0,0);
    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            {
            break;
            }
        }
            background.setPosition(0,0);
            Window.draw(background);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                Moose.moveRight();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                Moose.moveLeft();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && Moose.Ground == true) {
                Moose.Jump = true;
                Moose.Ground = false;
                acceleration = 25;
            }
            if (Moose.Ground == false && Moose.Jump == true) {
                acceleration = Moose.moveJump(acceleration);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                pongGame();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                flashlightGame();
            }
            if (Moose.MooseSprite.getGlobalBounds().intersects(platform.getGlobalBounds())) {
                cout << "SDFAJIASDFAJIO";
                Moose.Ground = true;
                Moose.Jump = false;
                Moose.MooseSprite.move(0,-1);
            }
//            if (!Player.getGlobalBounds().intersects(platform.getGlobalBounds())) {
//                 ground = false;
//                 down = true;
//            }
        platform.setPosition(500,340);
        Window.draw(Moose.MooseSprite);
        Window.draw(platform);
        Window.display();

        Window.clear();
    }
    return 0;
}
