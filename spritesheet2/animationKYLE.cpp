#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    enum Direction {Left, Right};

    int sourceX = 32, sourceY = Right;
    float x=100, y=245;

    sf::Vector2i source(32, Right);
    source.x = 10;

    float gravity = 0;
    bool jump = false, ground = true, down = true;
    bool up = false;

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(480, 320), "Sprite Sheet");

    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;

    sf::Texture backg;
    sf::Sprite background;

    if(!pTexture.loadFromFile("player.png"))
        std::cout << "ERROR" << std::endl;

    if(!backg.loadFromFile("bg.png"))
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and y == 245)
               {
                   gravity = -2;
                   up = true;
                cout << y << endl;
               }
               if (up == true and y > 240){
                y+=gravity;
                gravity+=.05;
                cout << y << endl;
                }
                if (y <= 240){
                up = false;
                }
                if (y < 245 and up == false){
                y+=gravity;
                gravity+=.05;
                cout << y << endl;
                }
                if (y >= 245){
                gravity = 0;
                y = 245;
                }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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
