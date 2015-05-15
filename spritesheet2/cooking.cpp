#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{



     sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "Sprite Sheet");
    Window.setFramerateLimit(169);



    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            {
            break;
            }
        }
    }
}
