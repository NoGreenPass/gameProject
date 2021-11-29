#include "Enemy.hpp"

Enemy::Enemy(){
    srand(time(0));
}

void Enemy::EnemyIsMoving(){}   /* to do: sviluppare il movimento del nemico */

void Enemy::EnemyPattern1(char m[][40], const int x, const int y){
    if(health == 1){
        casualEnemy = 1 + rand() % 4;
        switch (casualEnemy)
        {
        case 1:
            m[17][12] = EnemyChoice();
            m[18][35] = EnemyChoice();
            break;
        case 2:
            m[15][15]= EnemyChoice();
            m[18][6] = EnemyChoice();
            break;
        case 3:
            m[16][14] = EnemyChoice();
            m[17][31] = EnemyChoice();
            break;
        case 4:
            m[16][27] = EnemyChoice();
            m[18][20] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(health == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
            case 1:
                m[15][15] = EnemyChoice();
                m[17][31] = EnemyChoice();
                m[18][6] = EnemyChoice();
                break;
            case 2:
                m[16][27] = EnemyChoice();
                m[17][12] = EnemyChoice();
                m[18][20] = EnemyChoice();
                break;
            case 3:
                m[16][14] = EnemyChoice();
                m[18][35] = EnemyChoice();
                break;
            default:
                break;
            }
        }else{
            m[15][15]= EnemyChoice();
            m[16][14] = EnemyChoice();
            m[16][27] = EnemyChoice();
            m[17][12] = EnemyChoice();
            m[17][31] = EnemyChoice();
            m[18][6] = EnemyChoice();
            m[18][20] = EnemyChoice();
            m[18][35] = EnemyChoice();
        }
    }
}

void Enemy::EnemyPattern2 (char m[][40], const int x, const int y){
    if(health == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[12][33] = EnemyChoice();
            m[16][29] = EnemyChoice();
            m[18][4] = EnemyChoice();
            break;
        case 2:
            m[11][27] = EnemyChoice();
            m[14][33] = EnemyChoice();
            m[18][16] = EnemyChoice();
            break;
        case 3:
            m[13][36] = EnemyChoice();
            m[16][5] = EnemyChoice();
            m[18][33] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(health == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
            case 1:
                m[11][27] = EnemyChoice();
                m[12][33] = EnemyChoice();
                m[14][33] = EnemyChoice();
                m[16][29] = EnemyChoice();
                m[18][4] = EnemyChoice();
                m[18][16] = EnemyChoice();
                break;
            case 2:
                m[11][27] = EnemyChoice();
                m[13][36] = EnemyChoice();
                m[14][33] = EnemyChoice();
                m[16][5] = EnemyChoice();
                m[18][16] = EnemyChoice();
                m[18][33] = EnemyChoice();
                break;
            case 3:
                m[12][33] = EnemyChoice();               
                m[13][36] = EnemyChoice();
                m[16][5] = EnemyChoice();
                m[16][29] = EnemyChoice();
                m[18][4] = EnemyChoice();
                m[18][33] = EnemyChoice();
                break;
            default:
                break;
            }
        }else{
            m[11][27] = EnemyChoice();
            m[12][33] = EnemyChoice();
            m[13][36] = EnemyChoice();
            m[14][33] = EnemyChoice();
            m[16][5] = EnemyChoice();
            m[16][29] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][16] = EnemyChoice();
            m[18][33] = EnemyChoice();
        }
    }
}

void Enemy::EnemyPattern3 (char m[][40], const int x, const int y){
    if(health == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[16][17] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][36] = EnemyChoice();
            break;
        case 2:
            m[17][22] = EnemyChoice();
            m[18][8] = EnemyChoice();
            break;
        case 3:
            m[17][11] = EnemyChoice();
            m[18][28] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(health == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
                case 1:
                    m[16][17] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    m[18][8] = EnemyChoice();
                    m[18][36] = EnemyChoice();
                    break;
                case 2:
                    m[17][11] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][8] = EnemyChoice();
                    m[18][28] = EnemyChoice();
                    break;
                case 3:
                    m[16][17] = EnemyChoice();
                    m[17][11] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    m[18][28] = EnemyChoice();
                    m[18][36] = EnemyChoice();
                    break;
            }
        }else{
            m[16][17] = EnemyChoice();
            m[17][11] = EnemyChoice();
            m[17][22] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][8] = EnemyChoice();
            m[18][28] = EnemyChoice();
            m[18][36] = EnemyChoice();
        }
    }
}

void Enemy::EnemyPattern4 (char m[][40], const int x, const int y){
    if(health == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[9][15] = EnemyChoice();
            m[10][31] = EnemyChoice();
            m[13][11] = EnemyChoice();
            m[18][14] = EnemyChoice();
            break;
        case 2:
            m[12][16] = EnemyChoice();
            m[15][11] = EnemyChoice();
            m[18][27] = EnemyChoice();
            break;
        case 3:
            m[9][26] = EnemyChoice();
            m[10][19] = EnemyChoice();
            m[17][5] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(health == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
            case 1:
                m[9][15] = EnemyChoice();
                m[10][31] = EnemyChoice();
                m[12][16] = EnemyChoice();
                m[13][11] = EnemyChoice();
                m[15][11] = EnemyChoice();
                m[18][14] = EnemyChoice();
                m[18][27] = EnemyChoice();
                break;
            case 2:
                m[9][26] = EnemyChoice();
                m[10][19] = EnemyChoice();
                m[12][16] = EnemyChoice();
                m[15][11] = EnemyChoice();
                m[17][5] = EnemyChoice();
                m[18][27] = EnemyChoice();
                break;
            case 3:
                m[9][15] = EnemyChoice();
                m[9][26] = EnemyChoice();
                m[10][19] = EnemyChoice();
                m[10][31] = EnemyChoice();
                m[13][11] = EnemyChoice();
                m[17][5] = EnemyChoice();
                m[18][14] = EnemyChoice();
                break;
            default:
                break;
            }
    }else{
        m[9][15] = EnemyChoice();
        m[9][26] = EnemyChoice();
        m[10][19] = EnemyChoice();
        m[10][31] = EnemyChoice();
        m[12][16] = EnemyChoice();
        m[13][11] = EnemyChoice();
        m[15][11] = EnemyChoice();
        m[17][5] = EnemyChoice();
        m[18][14] = EnemyChoice();
        m[18][27] = EnemyChoice();
        }
    }
}

char Enemy::EnemyChoice(){
    casualEnemy = 1 + rand() % 3;
    switch (casualEnemy)
    {
    case 1:
        health = 50*health;
        return 'O';
        break;
    case 2:
        health = 30*health;
        return 'N';
        break;
    case 3:
        health = 10*health;
        return 'I';
        break;
    default:
        return ' ';
        break;
    }
}

void Enemy::EnemyPatternChoice(int bon, char m[][40], const int x, const int y){
    switch (bon)
    {
    case 1:
        EnemyPattern1(m, 20, 40);
        break;
    case 2:
        EnemyPattern2(m, 20, 40);
        break;
    case 3:
        EnemyPattern3(m, 20, 40);
        break;
    case 4:
        EnemyPattern4(m, 20, 40);
        break;
    default:
        break;
    }
}

void Enemy::EnemyUpdate(int diff){
    health = diff;
}

void Enemy::CancelEnemy(char m[][40], const int x, const int y, int a, int b){
    m[a][b] = ' ';
}