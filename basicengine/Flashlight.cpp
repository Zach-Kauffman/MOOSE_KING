#include "Flashlight.h"

Flashlight::Flashlight() {
    light1.loadFromFile("flashlight1.png");
    light2.loadFromFile("flashlight2.png");
    light3.loadFromFile("flashlight3.png");
    light4.loadFromFile("flashlight4.png");
    light5.loadFromFile("flashlight5.png");
    light6.loadFromFile("flashlight6.png");
    forest.loadFromFile("cavegogo.png");
    moosetexture.loadFromFile("Moosehead.png");
    font.loadFromFile("alba.TTF");
    float squarex = 0;
    squarey = 0;
    level = 1;
    found = 0;
    countdown = 20;
}

void Flashlight::variable(sf::RenderWindow&window) {
    if (level == 1) {
        light.setTexture(light1);
    }
    if (level == 2) {
        light.setTexture(light2);
    }
    if (level == 3) {
        light.setTexture(light3);
    }
    if (level == 4) {
        light.setTexture(light4);
    }
    if (level == 5) {
        light.setTexture(light5);
    }
    if (level == 6) {
        light.setTexture(light6);
    }
    mouse.setRadius(.5);
    background.setTexture(forest);
    Moose.setTexture(moosetexture);
    timer.setCharacterSize(50);
    timer.setPosition(0,0);
    timer.setFont(font);
    timer.setString(timestring);
    wintext.setCharacterSize(150);
    wintext.setPosition(0,10);
    wintext.setFont(font);
    losetext.setCharacterSize(150);
    losetext.setPosition(0,10);
    losetext.setFont(font);
}

void Flashlight::squareGenerator(sf::RenderWindow&window, sf::Clock&clock) {
    Moose.setPosition(rand()%900,rand()%500);
}

void Flashlight::game(sf::RenderWindow&window, sf::Clock&clock) {
    mousex = sf::Mouse::getPosition(window).x;
    mousey = sf::Mouse::getPosition(window).y;
    if (mousex < 0) {
        mousex = 0;
    }
    if (mousex > 1024) {
        mousex = 1024;
    }
    if (mousey < 0) {
        mousey = 0;
    }
    if (mousey > 768) {
        mousey = 768;
    }
    mouse.setPosition(mousex,mousey);
    light.setPosition(mousex - 1024, mousey - 768);
    window.draw(mouse);
    window.draw(background);
    window.draw(Moose);
    window.draw(light);
    window.draw(timer);
    if (found == 2) {
        level++;
        found = 0;
    }
    if (level >= 7) {
        win = true;
       restart(window);
    }
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds()>=1 and countdown > 0) {
        countdown--;
        std::cout << countdown;
        time(window,clock);
        clock.restart();
    }
    if (countdown <= 0) {
        win = false;
        restart(window);
    }
    if (mouse.getGlobalBounds().intersects(Moose.getGlobalBounds())) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                    found++;
                    squareGenerator(window,clock);
                    countdown+=5;
                    time(window,clock);
            }
        }
    }
}

void Flashlight::time(sf::RenderWindow&window,sf::Clock&clock) {
    std::ostringstream convert;
    convert << countdown;
    timestring = convert.str();
}

void Flashlight::restart(sf::RenderWindow&window) {
    if (win == true) {
        window.close();
    }
    if (win == false) {
//        losetext.setString("YOU LOSE BUM");
//        restartprompt.setCharacterSize(150);
//        restartprompt.setPosition(200,400);
//        restartprompt.setFont(font);
//        restartprompt.setString("Restart");
//        window.draw(losetext);
//        window.draw(restartprompt);
        sf::Event restartclick;
        if (mouse.getGlobalBounds().intersects(restartprompt.getGlobalBounds())) {
            while (window.pollEvent(restartclick))
            {
                if(restartclick.type == sf::Event::MouseButtonPressed) {
                    level = 1;
                    countdown = 20;
                    found = 0;
                }
            }
        }
        window.close();
    }
}
