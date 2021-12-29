#include "BulletTypeEnemy.hpp"

BulletTypeEnemy::BulletTypeEnemy(){}

void BulletTypeEnemy::setPosition( short x, short y ){
    this->x = x;
    this->y = y;
}

void BulletTypeEnemy::printBullet(){
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {y,x});
    putch('-');
    Sleep(50);
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {y,x});
    putch(' ');
}

bool BulletTypeEnemy::stopBullet( char matrix[][30], bool exist ){
     if( matrix[x][y] == '=' || matrix[x][y] == 'H' || matrix[x][y] == '$' || !exist ) return true;
    else return false;
}

void BulletTypeEnemy::moveBullet(){
    y--;
}

bool BulletTypeEnemy::heroHit( short posX, short posY ){
    if( x == posX && y == posY ) return true;
    else return false;
}

short BulletTypeEnemy::getX() {
    return x;
}

short BulletTypeEnemy::getY() {
    return y;
}