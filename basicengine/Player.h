#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Platform.h"

class Player {
public:
    Player(TextureHolder&);
    float moveJump(float);
    void moveRight();
    void moveLeft();
    void Animate();
    void checkCollisions(Platform,float);
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
