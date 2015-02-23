#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    enum Direction {Down, Left, Right, Up};

    int sourceX = 32, sourceY = Down;

    sf::Vector2i source(32, Down);
    source.x = 10;

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(800, 600), "Sprite Sheet");

    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;

    if(!pTexture.loadFromFile("player.png"))
        std::cout << "ERROR" << std::endl;

    playerImage.setTexture(pTexture);

    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            switch(Event.type)
            {
        case sf::Event::Closed:
            Window.close();
            break;
        case sf::Event::KeyPressed:
            if(Event.key.code == sf::Keyboard::Up)
                source.y = Up;
            else if(Event.key.code == sf::Keyboard::Down)
                source.y= Down;
            else if (Event.key.code == sf::Keyboard::Right)
                source.y= Right;
            else if(Event.key.code == sf::Keyboard::Left)
                source.y= Left;
            break;
            }
        }
        source.x++;
        if(source.x*32>=pTexture.getSize().x)
        source.x=0;
        playerImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32,32));
        Window.draw(playerImage);
        Window.display();
        Window.clear();
    }
    return 0;
}
