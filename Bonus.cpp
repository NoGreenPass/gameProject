#include "Bonus.hpp"

Bonus::Bonus(){
    srand(time(0));
}

void Bonus::bonusPattern1 (char m[][40], const int x, const int y){
    m[14][19] = bonusChoice();
}

void Bonus::bonusPattern2 (char m[][40], const int x, const int y){
    if(pointsEarned/100 == 1){
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[15][1] = bonusChoice();
            break;
        case 2:
            m[13][38] = bonusChoice();
            break;
        case 3:
            m[12][22] = bonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 == 2){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[13][38] = bonusChoice();
                m[15][1] = bonusChoice();
                break;
            case 2:
                m[12][22] = bonusChoice();
                m[13][38] = bonusChoice();
                break;
            case 3:
                m[12][22] = bonusChoice();
                m[15][1] = bonusChoice();
            default:
                break;
            }
        }else{
            m[12][22] = bonusChoice();
            m[13][38] = bonusChoice();
            m[15][1] = bonusChoice();
        }
    }
}

void Bonus::bonusPattern3 (char m[][40], const int x, const int y){
    if(pointsEarned/100 == 1){
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[15][5] = bonusChoice();
            break;
        case 2:
            m[16][14] = bonusChoice();
            break;
        case 3:
            m[16][33] = bonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 == 2){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[15][5] = bonusChoice();
                m[16][14] = bonusChoice();
                break;
            case 2:
                m[16][14] = bonusChoice();
                m[16][33] = bonusChoice();
                break;
            case 3:
                m[15][5] = bonusChoice();
                m[16][33] = bonusChoice();
            default:
                break;
            }
        }else{
            m[15][5] = bonusChoice();
            m[16][14] = bonusChoice();
            m[16][33] = bonusChoice();
        }
    }
}

void Bonus::bonusPattern4 (char m[][40], const int x, const int y){
    if(pointsEarned/100 < 5){
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[10][35] = bonusChoice();
            break;
        case 2:
            m[14][8] = bonusChoice();
            break;
        case 3:
            m[7][20] = bonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 < 10){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[10][35] = bonusChoice();
                m[14][8] = bonusChoice();
                break;
            case 2:
                m[7][20] = bonusChoice();
                m[14][8] = bonusChoice();
                break;
            case 3:
                m[7][20] = bonusChoice();
                m[10][35] = bonusChoice();
            default:
                break;
            }
        }else{
            m[7][20] = bonusChoice();    
            m[10][35] = bonusChoice();
            m[14][8] = bonusChoice();
        }
    }   
}

void Bonus::bonusPattern5 (char m[][40], const int x, const int y){
    if(pointsEarned/100 < 5){
        casualBonus = 1 + rand() % 3;
        switch (casualBonus)
        {
        case 1:
            m[15][32] = bonusChoice();
            break;
        case 2:
            m[12][11] = bonusChoice();
            break;
        case 3:
            m[12][35] = bonusChoice();
        default:
            break;
        }
    }else{
        if(pointsEarned/100 < 10){
            casualBonus = 1 + rand() % 3;
            switch (casualBonus)
            {
            case 1:
                m[15][32] = bonusChoice();
                m[12][11] = bonusChoice();
                break;
            case 2:
                m[12][11] = bonusChoice();
                m[12][35] = bonusChoice();
                break;
            case 3:
                m[15][32] = bonusChoice();
                m[12][35] = bonusChoice();
            default:
                break;
            }
        }else{
            m[15][32] = bonusChoice();    
            m[12][11] = bonusChoice();
            m[12][35] = bonusChoice();
        }
    }
}   

char Bonus::bonusChoice(){
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

void Bonus::bonusPatternChoice(int pat, char m[][40], const int x, const int y){
    switch(pat){
        case 1:
            bonusPattern1(m, 20, 40);
            break;
        case 2:
            bonusPattern2(m, 20, 40);
            break;
        case 3:
            bonusPattern3(m, 20, 40);
            break;
        case 4:
            bonusPattern4(m, 20, 40);
            break;
        case 5:
            bonusPattern5(m, 20, 40);
            break;
        default:
            break;
    }
}

void Bonus::bonusUpdate(int diff){
    pointsEarned = 100*diff;
    healthEarned = 10*diff;
}

int Bonus::getPoints(){
    return pointsEarned;
}

int Bonus::getHealth(){
    return healthEarned;
}

void Bonus::cancelBonus(char m[][40], const int x, const int y, int a, int b){
    m[a][b] = ' ';
}