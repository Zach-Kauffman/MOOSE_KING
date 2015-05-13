#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class Player {
public:
    Player();
    //MooseTexture = holder.getTexture("MT");
    void moveJump(float,float);
    void moveRight();
    void moveLeft();
    void Animate();

private:
    enum Cel {IdleRight, IdleLeft, Right, Left};
    int sourceX, sourceY;
    float x,y;
    sf::Vector2f location;
    sf::Texture *MooseTexture;
    sf::Sprite MooseSprite;
};


#endif // PLAYER_H
