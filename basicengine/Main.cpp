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
#include "Platform.h"
#include "Button.h"

using namespace std;

bool pongGame() {
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
    return false;
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
    return false;
}

void Game() {
    srand(time(NULL));
    float acceleration;
    float bgX = 0;
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "Sprite Sheet");
    Window.setFramerateLimit(18);
    sf::Vector2f backgroundPosition;
    Window.setKeyRepeatEnabled(false);
    TextureHolder TempTextureHolder;
    Player Moose(TempTextureHolder);
    Moose.MooseSprite.setOrigin(0,64);
    Platform TempPlatform;

    TempPlatform.addPlatform(sf::Vector2f(200,20),sf::Vector2f(500,240),sf::Color(255,0,0));
    TempPlatform.addPlatform(sf::Vector2f(1000,60),sf::Vector2f(0,340),sf::Color(255,255,0));
    TempPlatform.addPlatform(sf::Vector2f(400,60),sf::Vector2f(1140,340),sf::Color(255,255,0));
    TempPlatform.addPlatform(sf::Vector2f(100,20),sf::Vector2f(900,240),sf::Color(255,255,0));



    sf::Texture backg;
    sf::Sprite background;
    backgroundPosition.x = 0;
    backgroundPosition.y = 0;
    background.setPosition(backgroundPosition);
    if(!backg.loadFromFile("scrollingtest.png")) {
        std::cout << "ERROR" << std::endl;
    }
    Moose.MooseSprite.setPosition(500,300);

    Moose.Animate();
    background.setTexture(backg);
    TempPlatform.findLocation(Window);
    while(Window.isOpen()) {
        sf::Event Event;
        while(Window.pollEvent(Event)) {
            {
            break;
            }
        }
        Window.draw(background);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            bgX = Moose.moveRight(background,bgX);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            bgX = Moose.moveLeft(background,bgX);
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
        Moose.checkCollisions(TempPlatform,acceleration);
        background.setPosition(backgroundPosition.x + bgX, backgroundPosition.y);
        TempPlatform.scrollPlatforms(bgX);
        TempPlatform.drawPlatforms(Window);
        Window.draw(Moose.MooseSprite);
        Window.display();
        Window.clear();
    }
}

int main() {
    Button button;
    button.buttonLabel = "ENTER THE MOOSIVERSE";
    button.presser.setSize(sf::Vector2f(400,100));
    button.presser.setPosition(sf::Vector2f(500,200));
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "MOOSE");
    if(button.pressButton(Window) == true) {
        Game();
    }
    return 0;
}
