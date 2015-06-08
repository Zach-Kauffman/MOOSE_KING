#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Platform.h"

class Player {
public:
    Player(TextureHolder&);
    float moveJump(float);
    sf::Vector2f moveRight(sf::Sprite, sf::Vector2f);
    sf::Vector2f moveLeft(sf::Sprite, sf::Vector2f);
    void Animate();
    void checkCollisions(Platform,float);
    sf::Vector2f scrollBackground(sf::Sprite,sf::Vector2f);
    sf::Sprite MooseSprite;
    bool Ground,Jump,Down;
private:
    float Gravity;
    enum Cel {IdleRight, IdleLeft, Right, Left};
    sf::Vector2i source;
    float x,y;
    sf::Vector2f location;
    sf::Texture* MooseTexture;

};


#endif // PLAYER_H
