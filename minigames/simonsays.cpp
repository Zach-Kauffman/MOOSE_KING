#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;
class Flashlight
{
public:
    void squareGenerator(sf::RenderWindow&,sf::Clock&);
    void game(sf::RenderWindow&,sf::Clock&);
    void variable(sf::RenderWindow&);
    void reset(sf::RenderWindow&,sf::Clock&);
    sf::RectangleShape square[25];
    sf::CircleShape mouse;
    sf::CircleShape Moose;
    sf::Sprite background;
    sf::Texture forest;
    float squarex = 0, squarey = 0, mousex, mousey;
};
void Flashlight::variable(sf::RenderWindow&window)
{

    for (int i = 0; i < 25; i++)
    {
        square[i].setSize(sf::Vector2f(1024/5,768/5));
        square[i].setFillColor(sf::Color::Black);
        square[i].setPosition(squarex,squarey);
        if ((i + 1) % 5 == 0)
        {
            squarex = 0;
            squarey+=(768/5);
        }
        else
        {
            squarex+=(1024/5);
        }
    }
    mouse.setRadius(.5);
    background.setTexture(forest);
    Moose.setRadius(30);
    Moose.setFillColor(sf::Color::Green);
}
int main()
{
    Flashlight F;
    if (!F.forest.loadFromFile("ponggamebg.png"))
    {

    }
    sf::RenderWindow window(sf::VideoMode(1020,764), "FLESHLIGHT");
    sf::Clock clock;
    F.variable(window);
    F.squareGenerator(window,clock);
    while(window.isOpen())
    {
        window.clear(sf::Color::Blue);

        F.game(window,clock);
        window.display();
    }
}
void Flashlight::squareGenerator(sf::RenderWindow&window, sf::Clock&clock)
{
    Moose.setPosition(rand()%1020,rand()%764);
}
void Flashlight::game(sf::RenderWindow&window, sf::Clock&clock)
{
    mousex = sf::Mouse::getPosition(window).x;
    mousey = sf::Mouse::getPosition(window).y;
    mouse.setPosition(mousex,mousey);
    window.draw(background);
    window.draw(Moose);
    window.draw(mouse);
    for(int i = 0; i < 25; i++)
    {
        if(mouse.getGlobalBounds().intersects(square[i].getGlobalBounds()) )
        {
            if (mouse.getGlobalBounds().intersects(Moose.getGlobalBounds()))
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::MouseButtonPressed)
                    {
                      i++;
                squareGenerator(window,clock);
                    }
                }
            }
        }
        else
        {
           window.draw(square[i]);
        }
    }
}
