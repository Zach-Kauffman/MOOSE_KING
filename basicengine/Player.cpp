#include "Player.h"
#include "TextureHolder.h"

using namespace std;

Player::Player(TextureHolder& Temp){
    Ground = true;
    Jump = false;
    Down = true;
    x = 500;
    y = 320;
    Gravity = 2.5;
    Temp.addTexture("playerSpritesheet.png","playerSpritesheet.png");
    MooseTexture = Temp.getTexture("playerSpritesheet.png");
    MooseSprite.setTexture(Temp.getTextureRef("playerSpritesheet.png"));
    source.x = 10;
    source.y = Right;
}

float Player::moveJump(float acceleration) {
    MooseSprite.move(0,-acceleration);
    acceleration -= Gravity;
    return acceleration;
}

void Player::moveLeft() {
    MooseSprite.move(-5,0);
    location = MooseSprite.getPosition();
    source.y = Left;
    Animate();
}

void Player::moveRight() {
    MooseSprite.move(5,0);
    location = MooseSprite.getPosition();
    source.y = Right;
    Animate();
}

void Player::Animate() {
    source.x ++;
    if(source.x*64 >= MooseTexture->getSize().x) {
        source.x=0;
    }
    MooseSprite.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64,64));
}


