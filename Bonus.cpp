#include "Bonus.hpp"

Bonus::Bonus(int diff){
    pointsEarned = 100*diff;
    healthEarned = 10*diff;
}

void Bonus::BonusPattern1 (char m[][40], const int x, const int y){
    m[13][18] = BonusChoice();
}

void Bonus::BonusPattern2 (char m[][40], const int x, const int y){
    if(pointsEarned/100 == 1){
        srand(time(0));
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[15][1] = BonusChoice();
            break;
        case 2:
            m[13][38] = BonusChoice();
            break;
        case 3:
            m[12][20] = BonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 == 2){
            srand(time(0));
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[15][1] = BonusChoice();
                m[13][38] = BonusChoice();
                break;
            case 2:
                m[13][38] = BonusChoice();
                m[12][20] = BonusChoice();
                break;
            case 3:
                m[12][20] = BonusChoice();
                m[15][1] = BonusChoice();
            default:
                break;
            }
        }else{
            m[15][1] = BonusChoice();
            m[13][38] = BonusChoice();
            m[12][20] = BonusChoice();
        }

    }
}

void Bonus::BonusPattern3 (char m[][40], const int x, const int y){
    m[15][16] = BonusChoice();
}

void Bonus::BonusPattern4 (char m[][40], const int x, const int y){
    if(pointsEarned/100 < 5){
        srand(time(0));
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[13][35] = BonusChoice();
            break;
        case 2:
            m[8][29] = BonusChoice();
            break;
        case 3:
            m[6][20] = BonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 < 10){
            srand(time(0));
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[13][35] = BonusChoice();
                m[8][29] = BonusChoice();
                break;
            case 2:
                m[8][29] = BonusChoice();
                m[6][20] = BonusChoice();
                break;
            case 3:
                m[6][20] = BonusChoice();
                m[13][35] = BonusChoice();
            default:
                break;
            }
        }else{
            m[13][35] = BonusChoice();
            m[8][29] = BonusChoice();
            m[6][20] = BonusChoice();    
        }
    }   
}

char Bonus::BonusChoice(){
    srand(time(0));
    casualBonus = 1 + rand() % 2;
    switch(casualBonus){
        case 1:
            return 'P';
            break;
        case 2:
            return 'H';
            break;
        default:
            return ' ';
            break;
    }
}

void Bonus::getChoice(int pat, char m[][40], const int x, const int y){
    switch(pat){
        case 1:
            BonusPattern1(m, 20, 40);
            break;
        case 2:
            BonusPattern2(m, 20, 40);
            break;
        case 3:
            BonusPattern3(m, 20, 40);
            break;
        case 4:
            BonusPattern4(m, 20, 40);
            break;
        default:
            break;
    }
}

int Bonus::getPoints(){
    return pointsEarned;
}

int Bonus::getHealth(){
    return healthEarned;
}