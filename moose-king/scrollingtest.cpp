#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;
int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 400), "My window");
    sf::Sprite background;
    sf::Texture b;
    sf::CircleShape circle(10);
    float x = 5,x1 = 0,y = 320, y1 = 0, gravity = 0;
    bool up = false;
    if (!b.loadFromFile("scrollingtest.png")){

    }
    circle.setPosition(5,325);
    circle.setFillColor(sf::Color::Red);
    background.setTexture(b);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        background.setPosition(x1,y1);
        window.draw(background);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x > 200){
            x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x <= 200){
            x1++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x < 800){
            x++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x >= 800){
            x1--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and y == 320){
            gravity = -2;
            up = true;
        }
        if (up == true and y > 270){
            y+=gravity;
            gravity+=.01;
        }
        if (y <= 270){
            up = false;
        }
        if (y < 320 and up == false){
            y+=gravity;
            gravity+=.01;
        }
        if (y >= 320){
            gravity = 0;
            y = 320;
        }
        circle.setPosition(x,y);
        window.draw(circle);
        window.display();
    }

    return 0;
}
