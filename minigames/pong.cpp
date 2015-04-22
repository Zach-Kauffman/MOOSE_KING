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
    void restart(sf::RenderWindow&);
    void shake(sf::RenderWindow&);
    sf::RectangleShape player1,player2,barrier1,barrier2,scoreboard;
    sf::CircleShape ball;
    sf::Font font;
    sf::Text score1, score2, title;
    string score1string, score2string;
    float x = 512,y = 120,p1x = 0,p1y = 284, p2x = 1014, p2y = 234;
    float b1x, b1y, b2x, b2y, scoreboardx, scoreboardy, xspeed = .7, yspeed = .5;
    bool right = true, up = false;
    int paddlehits = 0, counter = 0, temp1 = 0, temp2 = 0;
    float g = 255, r = 255;
    float startingspeed = .7,p1score = 0, p2score = 0;
};
int main()
{
    int side = 0;
    pong p;
    if (!p.font.loadFromFile("alba.TTF"))
    {

    }
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
    player2.setOrigin(sf::Vector2f(10,50));
    ball.setRadius(10);
    ball.setPosition(x,y);
    ball.setFillColor(sf::Color::Green);
    barrier1.setPosition(0,90);
    barrier1.setSize(sf::Vector2f(1024,10));
    barrier2.setPosition(0,758);
    barrier2.setSize(sf::Vector2f(1024,10));
    score1.setFont(font);
    score1.setCharacterSize(70);
    score1.setPosition(10,10);
    score1.setString("0");
    score2.setFont(font);
    score2.setCharacterSize(70);
    score2.setPosition(914,10);
    score2.setString("0");
    title.setFont(font);
    title.setCharacterSize(90);
    title.setPosition(200,-20);
    title.setString("CADESUCKSKETBALL");
    scoreboard.setPosition(0,0);
    scoreboard.setSize(sf::Vector2f(1024,100));
    scoreboard.setFillColor(sf::Color::Black);

}
void pong::game (sf::RenderWindow & window)
{
    if (p2y > y and p2y >= 150 and x > 312 and right == true)
    {
                p2y -= 1;
    }
    else if (p2y < y and p2y <= 658 and x > 312 and right == true)
    {
                p2y+= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and p1y != 100)
    {
                p1y--;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  and p1y != 658)
    {
                p1y++;
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
    if (x <= 0)
    {
        p2score++;
        restart(window);
    }
    else if (x >= 1024)
    {
        p1score++;
        restart(window);

    }
    x+=xspeed;
    y+=yspeed;
    if (p1score > temp1)
    {
        score1.setColor(sf::Color(g,255,g));
        temp1++;
        g-=28.333;
    }
    if (p2score > temp2)
    {
        score2.setColor(sf::Color(255,r,r));
        temp2++;
        r-=28.333;
    }
    window.draw(scoreboard);
    ball.setPosition(x,y);
    player1.setPosition(p1x,p1y);
    player2.setPosition(p2x,p2y);
    window.draw(player1);
    window.draw(player2);
    window.draw(barrier1);
    window.draw(barrier2);
    window.draw(ball);
    window.draw(score1);
    window.draw(score2);
    window.draw(title);
}
void pong::restart(sf::RenderWindow & window)
{
    ostringstream convert;
    ostringstream converter;

    convert << p1score;
    score1string = convert.str();

    converter << p2score;
    score2string = converter.str();

    score1.setString(score1string);
    score2.setString(score2string);

    x = 512;
    y = 120;
    startingspeed*=-1;
    if (startingspeed < 0)
    {
        right = false;
    }
    if (startingspeed > 0)
    {
        right = true;
    }
    xspeed = startingspeed;
    yspeed = .5;
}
