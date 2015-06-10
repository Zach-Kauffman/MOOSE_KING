#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Platform.h"

class Player {
public:
    Player(TextureHolder&);
    float moveJump(float);
    float moveRight(sf::Sprite, float);
    float moveLeft(sf::Sprite, float);
    void Animate();
    void checkCollisions(Platform,float);
    float scrollBackground(sf::Sprite,float);
    sf::Sprite MooseSprite;
    bool Ground,Jump,Down;
    bool mRight, mLeft;
private:
    float Gravity;
    enum Cel {IdleRight, IdleLeft, Right, Left};
    sf::Vector2i source;
    float x,y;
    sf::Vector2f location;
    sf::Texture* MooseTexture;

};


#endif // PLAYER_H
