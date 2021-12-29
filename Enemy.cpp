#include "Enemy.hpp"

Enemy::Enemy(){
    exist = true;
}

void Enemy::initPosition( int x, int y ){
    this->x = x;
    this->y = y;
}

void Enemy::cancelEnemy( char matrix[][30] ){
    matrix[x][y] = ' ';
    exist = false;
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

void Enemy::reduceLife( char matrix[][30], int dmg ){
    life = life - dmg;
    if( life == 0 ) cancelEnemy( matrix );
    else matrix[x][y] = skin;
}