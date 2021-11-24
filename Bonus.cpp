#include "Bonus.hpp"

Bonus::Bonus(int diff){
    srand(time(0));
    pointsEarned = 100*diff;
    healthEarned = 10*diff;
}

void Bonus::BonusPattern1 (char m[][40], const int x, const int y){
    m[14][16] = BonusChoice();
}

void Bonus::BonusPattern2 (char m[][40], const int x, const int y){
    if(pointsEarned/100 == 1){
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
            m[12][22] = BonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 == 2){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[13][38] = BonusChoice();
                m[15][1] = BonusChoice();
                break;
            case 2:
                m[12][22] = BonusChoice();
                m[13][38] = BonusChoice();
                break;
            case 3:
                m[12][22] = BonusChoice();
                m[15][1] = BonusChoice();
            default:
                break;
            }
        }else{
            m[12][22] = BonusChoice();
            m[13][38] = BonusChoice();
            m[15][1] = BonusChoice();
        }
    }
}

void Bonus::BonusPattern3 (char m[][40], const int x, const int y){
    m[16][14] = BonusChoice();
}

void Bonus::BonusPattern4 (char m[][40], const int x, const int y){
    if(pointsEarned/100 < 5){
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[10][35] = BonusChoice();
            break;
        case 2:
            m[14][8] = BonusChoice();
            break;
        case 3:
            m[7][20] = BonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 < 10){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[10][35] = BonusChoice();
                m[14][8] = BonusChoice();
                break;
            case 2:
                m[7][20] = BonusChoice();
                m[14][8] = BonusChoice();
                break;
            case 3:
                m[7][20] = BonusChoice();
                m[10][35] = BonusChoice();
            default:
                break;
            }
        }else{
            m[7][20] = BonusChoice();    
            m[10][35] = BonusChoice();
            m[14][8] = BonusChoice();
        }
    }   
}

char Bonus::BonusChoice(){
    casualBonus = 1 + rand() % 2;
    switch(casualBonus){
        case 1:
            return '$';
            break;
        case 2:
            return '%';
            break;
        /* case 3:
                return '*';
                break;
        aumento danni proiettile */
        default:
            return ' ';
            break;
    }
}

int Bonus::BonusPatternChoice(int pat, char m[][40], const int x, const int y){
    switch(pat){
        case 1:
            BonusPattern1(m, 20, 40);
            return 1;
            break;
        case 2:
            BonusPattern2(m, 20, 40);
            return 2;
            break;
        case 3:
            BonusPattern3(m, 20, 40);
            return 3;
            break;
        case 4:
            BonusPattern4(m, 20, 40);
            return 4;
            break;
        default:
            return 0;
            break;
    }
}

int Bonus::getPoints(){
    return pointsEarned;
}

int Bonus::getHealth(){
    return healthEarned;
}