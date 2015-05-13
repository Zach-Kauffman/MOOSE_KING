 #include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

using namespace std;

int main()
{

    enum Direction {IdleRight, IdleLeft, Right, Left, Jump};

    int sourceX = 64, sourceY = Right;
    float x=500, y=320, gravity = 0;
    float x1=0 , y1=0;
    bool ground = true,jump = false,down = true;
    int c = 0;

    sf::Vector2i source(64, Right);
    source.x = 10;

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(1000, 400), "Sprite Sheet");
    Window.setFramerateLimit(24);

    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite Player;

    sf::Texture backg;
    sf::Sprite background;

    sf::Texture platformTexture;
//    sf::Sprite platform;
    sf::RectangleShape platform (sf::Vector2f(500,340));
    platform.setSize(sf::Vector2f(1280,32));
    platform.setPosition(500,340);
    sf::FloatRect platformHitbox = platform.getGlobalBounds();

    if(!pTexture.loadFromFile("playerBigSpritesheet.png")) {
        std::cout << "ERROR" << std::endl;
    }

    if(!backg.loadFromFile("scrollingtest.png")) {
        std::cout << "ERROR" << std::endl;
    }

    if(!platformTexture.loadFromFile("platform.png")) {
        std::cout << "ERROR" << std::endl;
    }

    Player.setTexture(pTexture);
    Player.setPosition(500,325);


    background.setTexture(backg);
    background.setPosition(x1,0);
    //platform.setTexture(platformTexture);
    //platform.setPosition (500,340);


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
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                source.y= Right;
                x += 5;
                source.x ++;
                if (x > 5) {
                    x1 += 5;
                }

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                source.y= Left;
                x -= 5;
                source.x ++;
                cout << x << endl;
                if (x < 1000) {
                    x1 -= 5;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and ground == true)
            {
                gravity = -10;
                ground = false;
                jump = true;
                down = false;
            }
            if (jump == true && down == false)
            {
                y+=gravity;
                gravity+=.5;
                if (down == false and gravity > 0){
                    down = true;
                }
            }

            if (down == true && ground == false){
                y-=gravity;
                gravity-=.5;
//                if ((Player.getGlobalBounds() - sf::Vector2f(0, y - gravity)).intersects(platform.getGlobalBounds())) {
//                    down == false;
//                    ground == true;
//                    sf::Vector2f platformLocation = platform.getPosition();
//                    y -= (y - platformLocation.y);
//                }

            }
            if (ground == true) {
                y -= .01;
                gravity = 0;
            }
            if (Player.getGlobalBounds().intersects(platform.getGlobalBounds())) {
                cout << "SDFAJIASDFAJIO";
                ground = true;
                jump = false;
                down = true;
                y -= 1;
            }
//            if (!Player.getGlobalBounds().intersects(platform.getGlobalBounds())) {
//                 ground = false;
//                 down = true;
//            }

        if(source.x*64>=pTexture.getSize().x)
        {
        source.x=0;
        }
        Player.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64,64));
        Player.setPosition(x,y);
        platform.setPosition(x1 + 500,y1 + 340);
        Window.draw(Player);
        Window.draw(platform);
        //cout << y << endl;
        Window.display();

        Window.clear();
    }
    return 0;
}
