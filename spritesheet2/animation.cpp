#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    enum Direction {Down, Left, Right, Up, Idle};

    int sourceX = 32, sourceY = Down;
    float x=200, y=200;

    sf::Vector2i source(32, Down);
    source.x = 10;

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(640, 480), "Sprite Sheet");

    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;

    sf::Texture backg;
    sf::Sprite background;

    if(!pTexture.loadFromFile("player2.png"))
        std::cout << "ERROR" << std::endl;

    if(!backg.loadFromFile("back.png"))
        std::cout << "ERROR" << std::endl;

    playerImage.setTexture(pTexture);
    background.setTexture(backg);

    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            {
            break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                source.y = Up;
                y-=.1;
                cout << y << endl;
                }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                source.y= Down;
                y+=.1;
                cout << y << endl;
                }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                source.y= Right;
                x+=.1;
                cout << x << endl;
                }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                source.y= Left;
                x-=.1;
                cout << x << endl;
                }
            else {
                source.y = Idle;
            }
        source.x++;
        if(source.x*32>=pTexture.getSize().x)
        {
        source.x=0;
        }
        playerImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32,32));
        playerImage.setPosition(x,y);
        Window.draw(background);
        Window.draw(playerImage);
        Window.display();
        Window.clear();
    }
    return 0;
}
