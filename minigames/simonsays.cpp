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
    float squarex = 0, squarey = 0, mousex, mousey;
    int level = 1, found = 0,countdown = 20;
};
void Flashlight::variable(sf::RenderWindow&window)
{
    if (level == 1)
        light.setTexture(light1);
    if (level == 2)
        light.setTexture(light2);
    if (level == 3)
        light.setTexture(light3);
    if (level == 4)
        light.setTexture(light4);
    if (level == 5)
        light.setTexture(light5);
    if (level == 6)
        light.setTexture(light6);
    mouse.setRadius(.5);
    background.setTexture(forest);
    Moose.setTexture(moosetexture);
}
int main()
{
    Flashlight F;
    if (!F.forest.loadFromFile("cavegogo.png"))
    {

    }
    if (!F.light1.loadFromFile("flashlight1.png"))
    {

    }
    if (!F.light2.loadFromFile("flashlight2.png"))
    {

    }
    if (!F.light3.loadFromFile("flashlight3.png"))
    {

    }
    if (!F.light4.loadFromFile("flashlight4.png"))
    {

    }
    if (!F.light5.loadFromFile("flashlight5.png"))
    {

    }
    if (!F.light6.loadFromFile("flashlight6.png"))
    {

    }
    if (!F.moosetexture.loadFromFile("Moosehead.png"))
    {

    }
    sf::RenderWindow window(sf::VideoMode(1020,764), "HIDE");
    sf::Clock clock;

    F.squareGenerator(window,clock);
    while(window.isOpen())
    {
        window.clear(sf::Color::Blue);
        F.variable(window);
        F.game(window,clock);
        window.display();
    }
}
void Flashlight::squareGenerator(sf::RenderWindow&window, sf::Clock&clock)
{
    Moose.setPosition(rand()%900,rand()%500);
}
void Flashlight::game(sf::RenderWindow&window, sf::Clock&clock)
{
    mousex = sf::Mouse::getPosition(window).x;
    mousey = sf::Mouse::getPosition(window).y;
    mouse.setPosition(mousex,mousey);
    light.setPosition(mousex - 1024, mousey - 768);
    window.draw(mouse);
    window.draw(background);
    window.draw(Moose);
    window.draw(light);
    if (found == 2)
    {
        level++;
        found = 0;
    }
    if (mouse.getGlobalBounds().intersects(Moose.getGlobalBounds()))
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                    found++;
                    squareGenerator(window,clock);
                    countdown+=5;
            }
        }
    }
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds()>=1)
    {
        countdown--;
        cout << countdown;
        clock.restart();
    }
}
