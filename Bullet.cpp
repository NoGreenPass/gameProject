#include "Bullet.hpp"

Bullet::Bullet(){}

void Bullet::setPosition( int x, int y ){
    this->x = x;
    this->y = y;
}

void Bullet::moveBullet( int dir ){
    if( dir == 1 ) y++;
    else y--;
}
void Bullet::spawnBullet( char matrix[][30] ){
    matrix[x][y] = '-';
}

void Bullet::cancelBullet( char matrix[][30] ){
    matrix[x][y] = ' '; 
}

bool Bullet::stopBullet( char matrix[][30] ){
    if( matrix[x][y] == '=' || matrix[x][y] == 'H' || matrix[x][y] == '$' ) return false;
    else return true;
}

int Bullet::getX(){
    return x;
}

int Bullet::getY(){
    return y;
}
