#include "Enemy.hpp"

Enemy::Enemy(){
    setExistence( true );
}

void Enemy::initPosition( int x, int y ){
    this->x = x;
    this->y = y;
}

char Enemy::getSkin(){
    return skin;
}

int Enemy::getX(){
    return x;
}

int Enemy::getY(){
    return y;
}

void Enemy::setExistence( bool tmp ){
    exist = tmp;
}

bool Enemy::getExistence(){
    return exist;
}

int Enemy::getRange(){
    return bulletRange;
}

int Enemy::getDamage(){
    return damage;
}

int Enemy::getBulletDamage(){
    return bulletDamage;
}

int Enemy::getLife(){
    return life;
}

void Enemy::reduceLife( int dmg ){
    life = life - dmg;
}