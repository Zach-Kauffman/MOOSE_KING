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
    int x = 5,x1 = 0;
    if (!b.loadFromFile("test.png")){

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
        window.clear(sf::Color::White);
        background.setPosition(x1,0);
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
        circle.setPosition(x,320);
        window.draw(circle);
        window.display();
    }

    return 0;
}
