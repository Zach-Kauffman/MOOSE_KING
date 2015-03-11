#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{

    enum Direction {Left, Right,nothing, Jump};

    int sourceX = 32, sourceY = Right;
    float x=500, y=320, gravity = 0;
    float x1=0 , y1=0;
    bool ground = true,jump = false,down = true, scroll = false;
    int c = 0;

    sf::Vector2i source(32, Right);
    source.x = 10;

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "Sprite Sheet");
    Window.setFramerateLimit(240);

    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;

    sf::Texture backg;
    sf::Sprite background;

    if(!pTexture.loadFromFile("player3.png"))
        std::cout << "ERROR" << std::endl;

    if(!backg.loadFromFile("scrollingtest.png"))
        std::cout << "ERROR" << std::endl;

    playerImage.setTexture(pTexture);
    playerImage.setPosition(5,325);
    background.setTexture(backg);
    background.setPosition(x1,0);

    while(Window.isOpen())
    {
        sf::Event Event;
        while(Window.pollEvent(Event))
        {
            {
            break;
            }
        }
            background.setPosition(x1,0);
            Window.draw(background);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x < 800)
                {
                source.y= Right;
                x+=1;
                cout << x << endl;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and x >= 800 and x1 >= -1000)
                {
                source.y= Right;
                x1-=1;
                cout << x << endl;
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)and x > 200)
                {
                source.y= Left;
                x-=1;
                cout << x << endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x1 == 0){
                x--;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and x <= 200 and x1 <= 0){
                x1++;
                scroll = true;
                }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and ground == true)
            {
                gravity = -2;
                ground = false;
                jump = true;
                down = false;
            }
            if (jump == true and down == false)
            {
                y+=gravity;
                gravity+=.015;
            }
            if (down == false and gravity > 0){
            down = true;
            }
            if (jump == true and down == true){
                y-=gravity;
                gravity-=.015;

            }
            if (y >= 320 and down == true){
                y = 320;
                jump = false;
                ground = true;
            }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) or sf::Keyboard::isKeyPressed(sf::Keyboard::Down) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        source.x++;
        if(source.x*32>=pTexture.getSize().x)
        {
        source.x=0;
        }
        playerImage.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32,32));
        playerImage.setPosition(x,y);
        Window.draw(playerImage);
        Window.display();

        Window.clear();
    }
    return 0;
}
