#include "Button.h"


Button::Button() {
    click=true;
    touch=false;
    font.loadFromFile("alba.TTF");
    buttonText.setFont(font);
    buttonText.setString("Enter the MOOSIVERSE");
    buttonText.setCharacterSize(69);
    buttonText.setColor(sf::Color(255,255,0));
    buttonText.setPosition(200,200);
    sillytext.setCharacterSize(75);
    sillytext.setColor(sf::Color(122,122,122));
    sillytext.setString("The government watches us");
    sillytext.setFont(font);
    presser.setOutlineThickness(10);
}

bool Button::pressButton(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (click)
        {
        window.clear();
        window.draw(presser);
        window.draw(buttonText);
        window.display();
        }
        while (click)
        {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f rectPos = presser.getPosition();
        int left = rectPos.x;
        int right = rectPos.x + presser.getSize().x;
        int top = rectPos.y;
        int bottom = rectPos.y + presser.getSize().y;

        if(left > mousePos.x || right < mousePos.x || top > mousePos.y || bottom < mousePos.y) {
            window.clear();
            presser.setFillColor(sf::Color(255,255,0));
            presser.setOutlineColor(sf::Color(150,150,150));
            window.draw(presser);
            window.draw(buttonText);
            window.display();
        }
        else
        {
            window.clear();
            presser.setFillColor(sf::Color(51,204,255));
            presser.setOutlineColor(sf::Color(51,102,255));
            window.draw(presser);
            window.draw(buttonText);
            window.draw(sillytext);
            window.display();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                touch = false;
                click = false;
                window.close();
                return true;

            }
        }
    }
    return 0;
}
}
