#include "Player.h"
#include "TextureHolder.h"
#include "Platform.h"

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

float Player::moveLeft(sf::Sprite background, float backgroundPositionx) {
    mRight = false;
    mLeft = true;
    MooseSprite.move(-5,0);
    location = MooseSprite.getPosition();
    source.y = Left;
    Animate();
    backgroundPositionx = scrollBackground(background,backgroundPositionx);
    return backgroundPositionx;
}

float Player::moveRight(sf::Sprite background, float backgroundPositionx) {
    mRight = true;
    mLeft = false;
    MooseSprite.move(5,0);
    location = MooseSprite.getPosition();
    source.y = Right;
    Animate();
    backgroundPositionx = scrollBackground(background,backgroundPositionx);
    return backgroundPositionx;
}

void Player::Animate() {
    source.x ++;
    if(source.x*64 >= MooseTexture->getSize().x) {
        source.x=0;
    }
    MooseSprite.setTextureRect(sf::IntRect(source.x * 64, source.y * 64, 64,64));
}

void Player::checkCollisions(Platform temp, float acceleration) {
    for (int ii = 0; ii < temp.platformList.size(); ii ++) {
        if(!temp.platformList[ii].getGlobalBounds().intersects(MooseSprite.getGlobalBounds()) && Jump == false) {
            //Ground = false;
            moveJump(-10);
        }
        if(temp.platformList[ii].getGlobalBounds().intersects(MooseSprite.getGlobalBounds())) {
            MooseSprite.setPosition(sf::Vector2f(MooseSprite.getPosition().x,(temp.platformList[ii].getPosition().y)));
            Ground = true;
            Jump = false;
        }
    }
}

float Player::scrollBackground(sf::Sprite background, float backgroundPositionx) {
    if (MooseSprite.getPosition().x > (background.getPosition().x + 630) and mRight == true) {
        backgroundPositionx -= 5;
        MooseSprite.move(-5,0);
    } else if (MooseSprite.getPosition().x > (background.getPosition().x + 630) and mLeft == true) {
        backgroundPositionx += 5;
    }
    if (MooseSprite.getPosition().x < background.getPosition().x + 325 and mLeft == true) {
        backgroundPositionx += 5;
        MooseSprite.move(5,0);
    } else if (MooseSprite.getPosition().x < background.getPosition().x + 325 and mRight == true) {
        backgroundPositionx -= 5;
    }
    return backgroundPositionx;
}

