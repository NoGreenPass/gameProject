#include "World.hpp"

World::World(){
    menu.startMenu();
    H.setSkin( menu.getPlayerSkin() );
    D.setName( menu.getPlayerName() );
}


void World::startGame() {
    int counter = 0;
    if( counter > 100 ) counter = 0;
    int i = -1;
    system("cls");
    createAndPrintFirstLevel();
    bool exit = false;
    while( D.getLifePoints() > 0 && !exit ){
        printMap( L.ptr -> matrix );
        D.printData();
        H.heroOnScreen();
        if( _kbhit() ){
            char keyPressed = _getch();
            SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
            switch( keyPressed ){
                case 'A':
                case 'a':
                    if( H.getColumnPosition() != 1 ){
                        printMap( L.ptr -> matrix );
                        H.heroOnScreen();
                        userPressA();
                    } else if( D.getLevelNumber() > 1) changeNode(0);
                    break; 
                case 'D':
                case 'd': 
                    if( H.getColumnPosition() != 28 ){
                        printMap( L.ptr -> matrix );
                        H.heroOnScreen();
                        userPressD();
                    }else{ 
                        if(D.getLevelNumber() == counterNode ) addNode();
                        else changeNode(1);
                    }
                    break;
                case 'W':
                case 'w':
                    printMap( L.ptr -> matrix );
                    H.heroOnScreen();
                    userPressW();
                    break;
                case 'S':
                case 's':
                    printMap( L.ptr -> matrix );
                    H.heroOnScreen();
                    userPressS();
                    break; 
                case 'X':
                case 'x':
                    exit = true;
                    break;
                default: 
                    break;
            }
        }
    }
    gameover();
}

void World::userPressA(){
    if( L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] == '=' ){
        if( L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] != '=' ){
            /*switch(L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1]){
                case '$':
                    D.riseScore(B.getPoints());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() - 1);
                    break;
                case '%':
                    D.riseLifePoints(B.getHealth());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() - 1);
                    break;
                case 'O':
                    D.reduceLifePoints(D.getDifficulty()*5);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() - 1);
                    break;
                case 'N':
                    D.reduceLifePoints(D.getDifficulty()*10);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() - 1);
                    break;
                case 'I':
                    D.reduceLifePoints(D.getDifficulty()*20);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() - 1);
                    break;
                default:
                    break;
            }*/
            for( int i = 0; i < MAXBONUS; i++ ){
                if( H.getRowPosition() == L.ptr -> bonusArray[i].getX() && ( H.getColumnPosition()-1 ) == L.ptr -> bonusArray[i].getY()){
                    if( L.ptr -> bonusArray[i].getExistence() ){
                        L.ptr -> matrix[L.ptr -> bonusArray[i].getX()][L.ptr -> bonusArray[i].getY()] = ' ';
                        L.ptr -> bonusArray[i].setExistence( false );
                        if( L.ptr -> bonusArray[i].getSkin() == '$' ){
                            BonusType$ $( D.getDifficulty() );
                            D.riseScore( $.getPointsEarned() );
                        } else {
                            BonusTypeH H( D.getDifficulty() );
                            D.riseLifePoints( H.getLifeEarned() );
                        }
                    }
                }
            }
            H.isMovingLeft();
            D.printData();
        }
    }
}

void World::userPressD(){
    if( L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] == '=' ){
        if( L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] != '=' ){
            /*switch(L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1]){
                case '$':
                    D.riseScore(B.getPoints());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() + 1);
                    break;
                case '%':
                    D.riseLifePoints(B.getHealth());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() + 1);
                    break;
                case 'O':
                    D.reduceLifePoints(D.getDifficulty()*5);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() + 1);
                    break;
                case 'N':
                    D.reduceLifePoints(D.getDifficulty()*10);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() + 1);
                    break;
                case 'I':
                    D.reduceLifePoints(D.getDifficulty()*20);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition(), H.getColumnPosition() + 1);
                    break;
                default:
                    break;
            } */
             for( int i = 0; i < MAXBONUS; i++ ){
                if( H.getRowPosition() == L.ptr -> bonusArray[i].getX() && ( H.getColumnPosition()+1 ) ==L.ptr -> bonusArray[i].getY() ){
                    if( L.ptr -> bonusArray[i].getExistence() ){
                        L.ptr -> matrix[L.ptr -> bonusArray[i].getX()][L.ptr -> bonusArray[i].getY()] = ' ';
                        L.ptr -> bonusArray[i].setExistence( false );
                        if( L.ptr -> bonusArray[i].getSkin() == '$' ){
                            BonusType$ $( D.getDifficulty() );
                            D.riseScore( $.getPointsEarned() );
                        } else {
                            BonusTypeH H( D.getDifficulty() );
                            D.riseLifePoints( H.getLifeEarned() );
                        }
                    }
                }
            }
            H.isMovingRight();
            D.printData();
        }
    }
}

void World::userPressW(){ 
    if(  H.getColumnPosition() != 28 && L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] == '='){
        /*
        switch(L.ptr -> matrix[H.getRowPosition() - 1][H.getColumnPosition() + 1]){
                case '$':
                    D.riseScore(B.getPoints());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition() - 1, H.getColumnPosition() + 1);
                    break;
                case '%':
                    D.riseLifePoints(B.getHealth());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition() - 1, H.getColumnPosition() + 1);
                    break;
                case 'O':
                    D.reduceLifePoints(D.getDifficulty()*5);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() - 1, H.getColumnPosition() + 1);
                    break;
                case 'N':
                    D.reduceLifePoints(D.getDifficulty()*10);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() - 1, H.getColumnPosition() + 1);
                    break;
                case 'I':
                    D.reduceLifePoints(D.getDifficulty()*20);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() - 1, H.getColumnPosition() + 1);
                    break;
                default:
                    break;
            } */
        H.isMovingUp(1);
        D.printData();
    }
    else if( H.getColumnPosition() != 1 &&  L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] == '='){
        /*
            switch(L.ptr -> matrix[H.getRowPosition() + 1][H.getColumnPosition() + 1]){
                case '$':
                    D.riseScore(B.getPoints());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition() + 1, H.getColumnPosition() + 1);
                    break;
                case '%':
                    D.riseLifePoints(B.getHealth());
                    B.cancelBonus(L.ptr -> matrix, X, Y, H.getRowPosition() + 1, H.getColumnPosition() + 1);
                    break;
                case 'O':
                    D.reduceLifePoints(D.getDifficulty()*5);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() + 1, H.getColumnPosition() + 1);
                    break;
                case 'N':
                    D.reduceLifePoints(D.getDifficulty()*10);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() + 1, H.getColumnPosition() + 1);
                    break;
                case 'I':
                    D.reduceLifePoints(D.getDifficulty()*20);
                    L.ptr -> E.CancelEnemy(L.ptr -> matrix, X, Y, H.getRowPosition() + 1, H.getColumnPosition() + 1);
                    break;
                default:
                    break;
            } */
        H.isMovingUp(0);
        D.printData();
    }
}

void World::userPressS(){
        if(  H.getRowPosition() != 8 && L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] != '='){
            if( L.ptr -> matrix[H.getRowPosition()+2][H.getColumnPosition()+1] != '=' ){
                short tmp = H.getColumnPosition() + 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(7, tmp );
                H.isMovingDown(1);
            } else H.isMovingDown(1);
        }
        else if( H.getRowPosition() != 8 &&  L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] != '='){
            if( L.ptr -> matrix[H.getRowPosition()+2][H.getColumnPosition()-1] != '=' ){
                short newColumnPosition = H.getColumnPosition() - 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(7, newColumnPosition );
                H.isMovingDown(0);
            } else H.isMovingDown(0);
        }
}

void World::createAndPrintFirstLevel(){
    counterNode = 1;
    D.riseLevelNumber();
    tmp = new Pointers;
    tmp -> prec = p;
    q = tmp;
    p = tmp;	
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;  
    Map M;
    M.initLevel( L.ptr -> matrix );
    chargeBonus();
    //B.bonusUpdate(D.getDifficulty());
    //L.ptr -> E.EnemyUpdate(D.getDifficulty());
    //P.patternChoice( L.ptr -> matrix, X, Y );
    //B.bonusPatternChoice( P.getPlatformNumber(),  L.ptr -> matrix, X, Y);
    //L.ptr -> E.EnemyPatternChoice( P.getPlatformNumber(), L.ptr -> matrix, X, Y);
    printMap( L.ptr ->matrix );
    H.setHeroPosition( 8,1 );
    H.heroOnScreen();
    D.printData();
}

void World::addNode() {
    counterNode++;
    D.riseLevelNumber();
    tmp = new Pointers;
    tmp -> prec = p;
    p->next = tmp;
    p = tmp;
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;
    Map M;
    M.initLevel( L.ptr -> matrix );
    chargeBonus();
    //addEmptySpace(L.ptr->matrix);
    //topDownWall(L.ptr ->matrix);
    //Platform P;
    //B.bonusUpdate(D.getDifficulty());
    //L.ptr -> E.EnemyUpdate(D.getDifficulty());
    //P.patternChoice( L.ptr -> matrix, X, Y );
    //B.bonusPatternChoice( P.getPlatformNumber(),  L.ptr -> matrix, X, Y);
    //L.ptr -> E.EnemyPatternChoice( P.getPlatformNumber(), L.ptr -> matrix, X, Y);
    printMap( L.ptr ->matrix );
    H.setHeroPosition( 8,1 );
    H.heroOnScreen();
    D.printData();
}

void World::changeNode( bool direction ) { 
    if( !direction ){ // direction == 0 se hero si sposta all'indietro
        L.ptr = L.ptr -> prec;
        D.reduceLevelNumber();
        printMap(L.ptr ->matrix);
        H.setHeroPosition( 8,28 );
        H.heroOnScreen();
        D.printData();
    } else{
        L.ptr = L.ptr -> next;
        D.riseLevelNumber();
        printMap(L.ptr ->matrix);
        H.setHeroPosition( 8,1 );
        H.heroOnScreen();
        D.printData();
    }
}

void World::chargeBonus(){
    srand(time(0));
    int k = 0; // actual bonus number
    for( int i = 0; i < 10; i++ ){
        for( int j = 0; j < 30; j++ ){
            if( L.ptr -> matrix[i][j] == 'Y' ){
                int casualBonus = rand() % 2;
                if( casualBonus == 0 ){
                    BonusType$ $( D.getDifficulty() );
                    L.ptr -> matrix[i][j] = $.getSkin();
                    $.initPosition( i, j );
                    L.ptr -> bonusArray[k] = $;
                } else{
                    BonusTypeH H( D.getDifficulty() );
                    L.ptr -> matrix[i][j] = H.getSkin();
                    H.initPosition( i, j );
                    L.ptr -> bonusArray[k] = H;
                }
                k++;
            }
        }
    }
}

void World::printMap(char m[][30]) {
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
    for( int i = 0; i < 10; i++ ){
        for( int j = 0; j < 30; j++ ){
            cout << m[i][j];
        }
        cout<<endl;
    }
}

void World::gameover() {
    menu.endGame();
    D.printName();
    cout << "\t";
    D.printScore();
    cout << "\t\t";
    D.printLevelNumber();
    cout << endl << endl << "Premere X per uscire." << endl;
    while( getch() != 'x' )
    menu.ExitMenu();
}


