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
    sf::RectangleShape platform(sf::Vector2f(30,5));

    float x = 500,x1 = 0,y = 0, y1 = 0, gravity = 0,recx = 200,recy = 200;
    bool jump = false, ground = true, down = true;
    if (!b.loadFromFile("scrollingtest.png")){

    }
    circle.setPosition(5,325);
    circle.setFillColor(sf::Color::Red);
    background.setTexture(b);
    platform.setFillColor(sf::Color::Black);
    platform.setPosition(sf::Vector2f(recx,recy));
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        background.setPosition(x1,y);
        platform.setPosition(sf::Vector2f(recx,recy));
        window.draw(background);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x > 200){
//            x--;
//        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x1 <=500){
            x1++;
            recx++;
        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x < 800){
//            x++;
//        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x1 >= -1500){
            x1--;
            recx--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and ground == true){
            gravity = 2;
            jump = true;
            ground = false;
            down = false;
        }
        if (jump == true){
            y+=gravity;
            gravity-=.01;
        }
        if (y >= 50){
            down = true;
        }
        if (y <= 5 and down == true){
            y = 5;
            jump = false;
            ground = true;
        }
        circle.setPosition(x,325);
        window.draw(circle);
        window.draw(platform);
        window.display();
    }

    return 0;
}
