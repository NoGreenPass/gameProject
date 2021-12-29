#include "BulletTypeHero.hpp"

BulletTypeHero::BulletTypeHero( int x, int y ){
    // set position bullet
    this->x = x;
    this->y = y;
}

void BulletTypeHero::printBullet() {
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {short(y), short(x)});
    putch('-');
    Sleep(20);
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {short(y), short(x)});
    putch(' ');
}

bool BulletTypeHero::stopBullet( char matrix[][30] ) {
    if( matrix[x][y] == '=' || matrix[x][y] == 'H' || matrix[x][y] == '$' ) return true;
    else return false;
}

void BulletTypeHero::moveBullet( int dir ) {
    if(dir == 1) y++;
    else y--;
}

bool BulletTypeHero::enemyHit( char matrix[][30] ) {
    if( matrix[x][y] == 'N' || matrix[x][y] == 'O' || matrix[x][y] == 'I' ) return true;
    else return false;
}

int BulletTypeHero::getRange() {
    return range;
}

int BulletTypeHero::getX() {
    return x;
}

int BulletTypeHero::getY() {
    return y;
}
