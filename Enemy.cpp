#include "Enemy.hpp"

Enemy::Enemy(){
    srand(time(0));
}

int Enemy::EnemyIsMoving( char map[][40], const int x, const int y, short heroPositionX, short heroPositionY ){
    for( int i = 0; i <= countEnemy; i++ ){
        if( enemyArray[i].death == false ){
            if( enemyArray[i].direction ){
                map[enemyArray[i].x][enemyArray[i].y-1] = ' ';
                map[enemyArray[i].x][enemyArray[i].y] = enemyArray[i].skin;
                enemyArray[i].direction = false;
                if( enemyArray[i].x == heroPositionX && enemyArray[i].y == heroPositionY){
                    enemyArray[i].death = true;
                    map[enemyArray[i].x][enemyArray[i].y] = ' ';
                    return i;
                } 
            }
            else{
                map[enemyArray[i].x][enemyArray[i].y] = ' ';
                map[enemyArray[i].x][enemyArray[i].y-1] = enemyArray[i].skin;
                enemyArray[i].direction = true;
                if( enemyArray[i].x == heroPositionX && (enemyArray[i].y-1) == heroPositionY){
                    enemyArray[i].death = true;
                    map[enemyArray[i].x][enemyArray[i].y-1] = ' ';
                    return i;
                }
            }
        }
    }
    return -1;
} 

void Enemy::EnemyPattern1(char m[][40], const int x, const int y){ 
    if(difficulty == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[16][15] = EnemyChoice();
            m[17][12] = EnemyChoice();
            m[18][35] = EnemyChoice();
            break;
        case 2:
            m[15][17]= EnemyChoice();
            m[18][6] = EnemyChoice();
            m[18][27]= EnemyChoice();
            break;
        case 3:
            m[16][27] = EnemyChoice();
            m[17][31] = EnemyChoice();
            m[18][17] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(difficulty == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
            case 1:
                m[15][17]= EnemyChoice();
                m[16][15] = EnemyChoice();
                m[17][12] = EnemyChoice();
                m[18][6] = EnemyChoice();
                m[18][27]= EnemyChoice();
                m[18][35] = EnemyChoice();
                break;
            case 2:
                m[15][17]= EnemyChoice();
                m[16][27] = EnemyChoice();
                m[17][31] = EnemyChoice();
                m[18][6] = EnemyChoice();
                m[18][17] = EnemyChoice();
                m[18][27]= EnemyChoice();
                break;
            case 3:
                m[16][15] = EnemyChoice();
                m[16][27] = EnemyChoice();
                m[17][12] = EnemyChoice();
                m[17][31] = EnemyChoice();
                m[18][17] = EnemyChoice();
                m[18][35] = EnemyChoice();
                break;
            default:
                break;
            }
        }else{
            m[15][17]= EnemyChoice();
            m[16][15] = EnemyChoice();
            m[16][27] = EnemyChoice();
            m[17][12] = EnemyChoice();
            m[17][31] = EnemyChoice();
            m[18][6] = EnemyChoice();
            m[18][17] = EnemyChoice();
            m[18][27] = EnemyChoice();
            m[18][35] = EnemyChoice();
        }
    }
}

void Enemy::EnemyPattern2 (char m[][40], const int x, const int y){
    if(difficulty == 1){
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
        if(difficulty == 2){
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
    if(difficulty == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[16][17] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][36] = EnemyChoice();
            break;
        case 2:
            m[16][26] = EnemyChoice();
            m[17][22] = EnemyChoice();
            m[18][8] = EnemyChoice();
            break;
        case 3:
            m[15][30] = EnemyChoice();
            m[16][9] = EnemyChoice();
            m[18][28] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(difficulty == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
                case 1:
                    m[16][17] = EnemyChoice();
                    m[16][26] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    m[18][8] = EnemyChoice();
                    m[18][36] = EnemyChoice();
                    break;
                case 2:
                    m[15][30] = EnemyChoice();
                    m[16][9] = EnemyChoice();
                    m[16][26] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][8] = EnemyChoice();
                    m[18][28] = EnemyChoice();
                    break;
                case 3:
                    m[15][30] = EnemyChoice();
                    m[16][9] = EnemyChoice();
                    m[16][17] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    m[18][28] = EnemyChoice();
                    m[18][36] = EnemyChoice();
                    break;
            }
        }else{
            m[15][30] = EnemyChoice();
            m[16][9] = EnemyChoice();
            m[16][17] = EnemyChoice();
            m[16][26] = EnemyChoice();
            m[17][22] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][8] = EnemyChoice();
            m[18][28] = EnemyChoice();
            m[18][36] = EnemyChoice();
        }
    }
}

void Enemy::EnemyPattern4 (char m[][40], const int x, const int y){
    if(difficulty == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[9][15] = EnemyChoice();
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
            m[10][31] = EnemyChoice();
            m[17][5] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(difficulty == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
            case 1:
                m[9][15] = EnemyChoice();
                m[12][16] = EnemyChoice();
                m[13][11] = EnemyChoice();
                m[15][11] = EnemyChoice();
                m[18][14] = EnemyChoice();
                m[18][27] = EnemyChoice();
                break;
            case 2:
                m[9][26] = EnemyChoice();
                m[10][31] = EnemyChoice();
                m[12][16] = EnemyChoice();
                m[15][11] = EnemyChoice();
                m[17][5] = EnemyChoice();
                m[18][27] = EnemyChoice();
                break;
            case 3:
                m[9][15] = EnemyChoice();
                m[9][26] = EnemyChoice();
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

void Enemy::EnemyPattern5 (char m[][40], const int x, const int y){
    if(difficulty == 1){
        casualEnemy = 1 + rand() % 3;
        switch (casualEnemy)
        {
        case 1:
            m[14][12] = EnemyChoice();
            m[16][25] = EnemyChoice();
            m[18][4] = EnemyChoice();
            break;
        case 2:
            m[13][32] = EnemyChoice();
            m[16][4] = EnemyChoice();
            m[18][15] = EnemyChoice();
            break;
        case 3:
            m[13][15] = EnemyChoice();
            m[16][30] = EnemyChoice();
            m[17][22] = EnemyChoice();
            break;
        default:
            break;
        }
    }else{
        if(difficulty == 2){
            casualEnemy = 1 + rand() % 3;
            switch (casualEnemy)
            {
                case 1:
                    m[13][32] = EnemyChoice();
                    m[14][12] = EnemyChoice();
                    m[16][4] = EnemyChoice();
                    m[16][25] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    m[18][15] = EnemyChoice();
                    break;
                case 2:
                    m[13][15] = EnemyChoice();
                    m[13][32] = EnemyChoice();
                    m[16][4] = EnemyChoice();
                    m[16][30] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][15] = EnemyChoice();
                    break;
                case 3:
                    m[13][15] = EnemyChoice();
                    m[14][12] = EnemyChoice();
                    m[16][25] = EnemyChoice();
                    m[16][30] = EnemyChoice();
                    m[17][22] = EnemyChoice();
                    m[18][4] = EnemyChoice();
                    break;
            }
        }else{
            m[13][15] = EnemyChoice();
            m[13][32] = EnemyChoice();
            m[14][12] = EnemyChoice();
            m[16][4] = EnemyChoice();
            m[16][25] = EnemyChoice();
            m[16][30] = EnemyChoice();
            m[17][22] = EnemyChoice();
            m[18][4] = EnemyChoice();
            m[18][15] = EnemyChoice();
        }
    }
}

char Enemy::EnemyChoice(){
    casualEnemy = 1 + rand() % 3;
    switch (casualEnemy)
    {
    case 1:
        return 'O';
        break;
    case 2:
        return 'N';
        break;
    case 3:
        return 'I';
        break;
    default:
        return ' ';
        break;
    }
}

void Enemy::EnemyPatternChoice(int pn, char m[][40], const int r, const int c){
    switch (pn)
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
    case 5:
        EnemyPattern5(m, 20, 40);
        break;
    default:
        break;
    }
    chargheEnemyArray( m, r, c );
}

void Enemy::EnemyUpdate(int diff){
    difficulty = diff;
    setCount();
}

void Enemy::setCount(){
    switch (difficulty)
    {
    case 1:
        countEnemy = 3;
        break;
    case 2:
        countEnemy = 6;
    case 3:
        countEnemy = 9;
    default:
        break;
    }
}

void Enemy::CancelEnemy(char m[][40], const int x, const int y, short a, short b){
    m[a][b] = ' ';
    for( int i = 0; i <= MAX_ENEMY_NUMBER; i++ ){
        if( enemyArray[i].x == a && enemyArray[i].y == b )
            enemyArray[i].death = true;
    }
}

void Enemy::chargheEnemyArray( char map[][40], const int r, const int c ){
    int count = 0;
     for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 40; j++ ){
            if( map[i][j] == 'O' ){
                enemyArray[count].skin = 'O';
                enemyArray[count].healt = 3;
                enemyArray[count].damage = 40;
                enemyArray[count].range = 1;
                enemyArray[count].x = i;
                enemyArray[count].y = j;
                enemyArray[count].death = false;
                enemyArray[count].direction = false;
                count++;
            }else if( map[i][j] == 'N' ){
                enemyArray[count].skin = 'N';
                enemyArray[count].healt = 2;
                enemyArray[count].damage = 20;
                enemyArray[count].range = 3;
                enemyArray[count].x = i;
                enemyArray[count].y = j;
                enemyArray[count].death = false;
                enemyArray[count].direction = false;
                count++;
            }else if( map[i][j] == 'I' ){
                enemyArray[count].skin = 'I';
                enemyArray[count].healt = 1;
                enemyArray[count].damage = 10;
                enemyArray[count].range = 5;
                enemyArray[count].x = i;
                enemyArray[count].y = j;
                enemyArray[count].death = false;
                enemyArray[count].direction = false;
                count++;
            } 
        }
    }
}