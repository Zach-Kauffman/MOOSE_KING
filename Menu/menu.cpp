#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <windows.h>
#include <sstream>

using namespace std;

int main()
{
        sf::RenderWindow window(sf::VideoMode(1024,768), "Menu");
        window.setFramerateLimit(60);

        bool click=true;
        bool touch=false;

        sf::Texture Background;
        if (!Background.loadFromFile("tennisbackground.png"))
        {
        cout << "ERROR";
        }

        sf::Font font;
        if(!font.loadFromFile("alba.TTF"))
        {
        cout << "ERROR";
        }

        sf::Sprite background;
        background.setTexture(Background);
        background.setPosition(0,0);

        sf::Text title;
        title.setFont(font);
        title.setString("Fresh Moose of Bel Air");
        title.setCharacterSize(74);
        title.setColor(sf::Color::Black);
        title.setPosition(150,150);

        sf::Text Start;
        Start.setFont(font);
        Start.setString("START");
        Start.setCharacterSize(69);
        Start.setColor(sf::Color::Black);
        Start.setPosition(430,600);

        sf::RectangleShape start(sf::Vector2f(120, 50));
        start.setSize(sf::Vector2f(400,200));
        start.setFillColor(sf::Color(255,0,251));
        start.setPosition(325,550);
        start.setOutlineThickness(10);
        start.setOutlineColor(sf::Color(158,158,158));

        while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (click)
        {
        window.clear();
        window.draw(background);
        window.draw(title);
        window.draw(start);
        window.draw(Start);
        window.display();
        }
        while (click)
        {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f rectPos = start.getPosition();
        int left = rectPos.x;
        int right = rectPos.x+400;
        int top = rectPos.y;
        int bottom = rectPos.y+200;

        if(left > mousePos.x || right < mousePos.x || top > mousePos.y || bottom < mousePos.y)
        {
            window.clear();
            start.setFillColor(sf::Color(255,255,0));
            start.setOutlineColor(sf::Color(158,158,158));
            window.draw(background);
            window.draw(title);
            window.draw(start);
            window.draw(Start);
            window.display();
        }
        else
        {
            window.clear();
            start.setFillColor(sf::Color(100,100,0));
            start.setOutlineColor(sf::Color(3,3,3));
            window.draw(background);
            window.draw(title);
            window.draw(start);
            window.draw(Start);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                touch = false;
                click = false;
                break;
            }
        }
    }

    return 0;
}
}
