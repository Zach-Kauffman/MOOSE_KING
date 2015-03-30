#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;
class pong
{
public:
    void game(sf::RenderWindow&);
    void variable(sf::RenderWindow&);
    sf::RectangleShape player1,player2,barrier1,barrier2;
    sf::CircleShape ball;
    sf::Clock clock;
    float x = 512,y = 20,p1x = 0,p1y = 284, p2x = 1004, p2y = 284, xspeed, yspeed;
    bool right = true, up = false;
    int paddlehits = 0, counter = 0;
};
int main()
{
    pong p;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    p.variable(window);

    while (window.isOpen())
    {
        window.clear(sf::Color(0,102,0));
        p.game(window);
        window.display();
    }
}
void pong::variable (sf::RenderWindow & window)
{
    player1.setPosition(p1x,p1y);
    player1.setSize(sf::Vector2f(20,100));
    player1.setFillColor(sf::Color::White);
    player2.setPosition(p2x,p2y);
    player2.setSize(sf::Vector2f(20,100));
    player2.setFillColor(sf::Color::White);
    ball.setRadius(10);
    ball.setPosition(x,y);
    ball.setFillColor(sf::Color::Green);
    barrier1.setPosition(0,-10);
    barrier1.setSize(sf::Vector2f(1024,10));
    barrier2.setPosition(0,768);
    barrier2.setSize(sf::Vector2f(1024,10));
    xspeed = .5;
    yspeed = .5;
}
void pong::game (sf::RenderWindow & window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and p1y != 0)
    {
                p1y--;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and p1y != 668)
    {
                p1y++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and p2y != 0)
    {
                p2y--;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  and p2y != 668)
    {
                p2y++;
    }
    if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) and right == false)
    {
        xspeed*=-1;
        paddlehits++;
        right = true;
    }
    else if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) and y <= p1x + 20 and up == true and right == true)
    {
        yspeed*=-1;
        xspeed*=-1;
        paddlehits++;
        right = false;
        up = false;
    }
    else if (ball.getGlobalBounds().intersects(player1.getGlobalBounds()) and y >= p1x + 80 and up == false and right == true)
    {
        yspeed*=-1;
        xspeed*=-1;
        paddlehits++;
        right = false;
        up = true;
    }
    if (ball.getGlobalBounds().intersects(player2.getGlobalBounds()) and right == true)
    {
        xspeed*=-1;
        paddlehits++;
        right = false;
    }
    else if (ball.getGlobalBounds().intersects(player2.getGlobalBounds()) and y <= p2x + 20 and up == true and right == false)
    {
        yspeed*=-1;
        xspeed*=-1;
        paddlehits++;
        right = true;
        up = false;
    }
    else if (ball.getGlobalBounds().intersects(player2.getGlobalBounds()) and y >= p2x + 80 and up == false and right == false)
    {
        yspeed*=-1;
        xspeed*=-1;
        paddlehits++;
        right = true;
        up = true;
    }
    if (ball.getGlobalBounds().intersects(barrier1.getGlobalBounds()))
    {
        yspeed*=-1;
        up = false;
    }
    else if (ball.getGlobalBounds().intersects(barrier2.getGlobalBounds()))
    {
        yspeed*=-1;
        up = true;
    }
    ///working here on speeding up game use sf clock
    if (paddlehits % 1 == 0 and paddlehits > counter)
    {
        xspeed+=(xspeed*.08);
        counter+=1;
        cout << xspeed << endl;
    }
    x+=xspeed;
    y+=yspeed;
    ball.setPosition(x,y);
    player1.setPosition(p1x,p1y);
    player2.setPosition(p2x,p2y);
    window.draw(player1);
    window.draw(player2);
    window.draw(barrier1);
    window.draw(barrier2);
    window.draw(ball);
}
