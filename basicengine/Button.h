#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
    public:
        Button();
        bool pressButton(sf::RenderWindow&);
        std::string buttonLabel;
        sf::RectangleShape presser;
    private:
        bool click, touch;
        sf::Font font;
        sf::Text buttonText;
        sf:: Text sillytext;


};
#endif // BUTTON_H
