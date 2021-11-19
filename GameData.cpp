#include "GameData.hpp"

GameData::GameData(){
    strcpy( name, "PlayerUnknown" );
    levelNumber = 0;
    lifePoints = 100;
    score = 0;
    difficulty = 1;
}

int GameData::getLevelNumber(){
    return levelNumber;
}

void GameData::riseLevelNumber(){
    levelNumber++;
    if( levelNumber % 5 == 0 ){
        difficulty++;
    }
}

void GameData::printData(){
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {45,4});
    cout << "Name: ";
    for(int i=0; name[i]!='\0'; i++) {
        cout << name[i];
    };
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {45,5});
    cout << "Life: " << lifePoints;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {45,6});
    cout << "Points: " << score;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {45,7});
    cout << "Level: " << levelNumber;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {45,8});
    cout << "Difficulty: ";
    printDifficulty();
}

int GameData::getLifePoints(){
    return lifePoints;
}
void GameData::riseLifePoints( int lp ){
    lifePoints = lifePoints + lp;
}
void GameData::reduceLifePoints( int lp ){
    lifePoints = lifePoints - lp;
}

void GameData::riseScore( int s ){
    score = score + s;
}
void GameData::reduceScore(int s ){
    score = score - s;
}

void GameData::printDifficulty(){
    if( difficulty >= 1 && difficulty <= 5 ) cout << "Easy";
    else if( difficulty < 10 ) cout << "Medium";
         else cout << "Hard"; // *DA AMPLIARE* 
}
int  GameData::getDifficulty(){
    return difficulty;
}

void GameData::setName( char n[] ){
    strcpy( name, n );
}

