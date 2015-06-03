#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <sstream>
#include "Pong.h"
using namespace std;

int main()
{
    int side = 0;
    Pong p;
    if (!p.font.loadFromFile("alba.TTF")) {

    }
    sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");
    p.variable(window);
    while (window.isOpen())
    {
        window.clear(sf::Color(0,102,0));
        p.game(window);
        window.display();
    }
}
