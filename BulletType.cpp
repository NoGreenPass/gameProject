#include "BulletType.hpp"

BulletTypeHero::BulletTypeHero(){
    range = 3; // default range
}

bool BulletTypeHero::enemyHit( char matrix[][30] ){
    if( matrix[x][y] == 'N' || matrix[x][y] == 'O' || matrix[x][y] == 'I' ) return true;
    else return false;
}

int BulletTypeHero::getRange(){
    return range;
}