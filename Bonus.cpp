#include "Bonus.hpp"

Bonus::Bonus(){
    setExistence( true );
}

void Bonus::initPosition( int x, int y ){
    this->x = x;
    this->y = y;
}

char Bonus::getSkin(){
    return skin;
}

int Bonus::getX(){
    return x;
}

int Bonus::getY(){
    return y;
}

void Bonus::setExistence( bool tmp ){
    exist = tmp;
}

bool Bonus::getExistence(){
    return exist;
}