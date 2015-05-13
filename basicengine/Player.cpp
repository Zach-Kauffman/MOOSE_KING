
#include "Player.h"
#include "TextureHolder.h"

using namespace std;

Player::Player(){

    x = 500;
    y = 320;
    //MooseTexture = Temp.getTexture("playerSpritesheet.png");
}

void Player::moveJump(float gravityCoefficient, float Gravity) {

}

void Player::moveLeft() {
    MooseSprite.move(-5,0);
    location = MooseSprite.getPosition();
    Animate();
}

void Player::moveRight() {

}

void Player::Animate() {

}


