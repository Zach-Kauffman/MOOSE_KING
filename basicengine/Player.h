#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Player {
public:
    Player(TextureHolder&);
    void moveJump(float,float);
    void moveRight();
    void moveLeft();
    void Animate();
    sf::Sprite MooseSprite;
private:
    bool Ground,Jump,Down;
    enum Cel {IdleRight, IdleLeft, Right, Left};
    sf::Vector2i source;
    float x,y;
    sf::Vector2f location;
    sf::Texture* MooseTexture;

};


#endif // PLAYER_H
