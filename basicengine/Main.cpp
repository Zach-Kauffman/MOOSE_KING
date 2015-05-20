#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Player.h"
#include "TextureHolder.h"

using namespace std;

int main()
{
    bool ground = true,jump = false,down = true;
    int c = 0;
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
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and ground == true)
//            {
//                gravity = -10;
//                ground = false;
//                jump = true;
//                down = false;
//            }
//            if (jump == true && down == false)
//            {
//                y+=gravity;
//                gravity+=.5;
//                if (down == false and gravity > 0){
//                    down = true;
//                }
//            }
//
//            if (down == true && ground == false){
//                y-=gravity;
//                gravity-=.5;
////                if ((Player.getGlobalBounds() - sf::Vector2f(0, y - gravity)).intersects(platform.getGlobalBounds())) {
////                    down == false;
////                    ground == true;
////                    sf::Vector2f platformLocation = platform.getPosition();
////                    y -= (y - platformLocation.y);
////                }
//
//            }
//            if (ground == true) {
//                y -= .01;
//                gravity = 0;
//            }
            if (Moose.MooseSprite.getGlobalBounds().intersects(platform.getGlobalBounds())) {
                cout << "SDFAJIASDFAJIO";
                ground = true;
                jump = false;
                down = true;
                Moose.MooseSprite.move(0,-1);
            }
//            if (!Player.getGlobalBounds().intersects(platform.getGlobalBounds())) {
//                 ground = false;
//                 down = true;
//            }
        platform.setPosition(500,340);
        Window.draw(Moose.MooseSprite);
        Window.draw(platform);
        //cout << y << endl;
        Window.display();

        Window.clear();
    }
    return 0;
}
