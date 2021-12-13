#include "World.hpp"

World::World() {
    M.startMenu();
    H.setSkin( M.getPlayerSkin() );
    D.setName(M.getPlayerName());
}


void World::startGame() {
    int counter = 0;
    if( counter > 100 ) counter = 0;
    int i = -1;
    system("cls");
    createAndPrintFirstLevel();
    bool exit = false;
    while( D.getLifePoints() > 0 && !exit ){
        counter = counter + 1;
        if( counter % 50 == 0 ){
            i = L.ptr -> E.EnemyIsMoving( L.ptr ->matrix, X, Y, H.getRowPosition(), H.getColumnPosition() );
            if( i != -1 ) D.reduceLifePoints( L.ptr -> E.enemyArray[i].damage );
        }
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
                    if( H.getColumnPosition() != 39 ){
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
    if( L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] == '=' )
        if( L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] != '=' ){
            switch(L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1]){
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
            }
            H.isMovingLeft();
            D.printData();
        }
}

void World::userPressD(){
    if( L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] == '=' )
        if( L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] != '=' ){
            switch(L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1]){
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
            }
            H.isMovingRight();
            D.printData();
        }
}

void World::userPressW(){ 
    if(  H.getColumnPosition() != 39 && L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] == '='){
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
            }
        H.isMovingUp(1);
        D.printData();
    }
    else if( H.getColumnPosition() != 1 &&  L.ptr -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] == '='){
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
            }
        H.isMovingUp(0);
        D.printData();
    }
}

void World::userPressS(){
        if(  H.getRowPosition() != 18 && L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] != '='){
            if( L.ptr -> matrix[H.getRowPosition()+2][H.getColumnPosition()+1] != '=' ){
                short tmp = H.getColumnPosition() + 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(17, tmp );
                H.isMovingDown(1);
            } else H.isMovingDown(1);
        }
        else if( H.getRowPosition() != 18 &&  L.ptr -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] != '='){
            if( L.ptr -> matrix[H.getRowPosition()+2][H.getColumnPosition()-1] != '=' ){
                short newColumnPosition = H.getColumnPosition() - 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(17, newColumnPosition );
                H.isMovingDown(0);
            } else H.isMovingDown(0);
        }
}

void World::createAndPrintFirstLevel(){
    counterNode = 1;
    D.riseLevelNumber();
    tmp = new Map;
    tmp -> prec = p;
    q = tmp;
    p = tmp;	
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;  
    addEmptySpace( L.ptr ->matrix );
    leftWall( L.ptr ->matrix );
    topDownWall( L.ptr ->matrix );
    Platform P;
    B.bonusUpdate(D.getDifficulty());
    L.ptr -> E.EnemyUpdate(D.getDifficulty());
    P.patternChoice( L.ptr -> matrix, X, Y );
    B.bonusPatternChoice( P.getPlatformNumber(),  L.ptr -> matrix, X, Y);
    L.ptr -> E.EnemyPatternChoice( P.getPlatformNumber(), L.ptr -> matrix, X, Y);
    printMap( L.ptr ->matrix );
    H.setHeroPosition( 18,1 );
    H.heroOnScreen();
    D.printData();
}

void World::addNode() {
    counterNode++;
    D.riseLevelNumber();
    tmp = new Map;
    tmp -> prec = p;
    p->next = tmp;
    p = tmp;
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;
    addEmptySpace(L.ptr->matrix);
    topDownWall(L.ptr ->matrix);
    Platform P;
    B.bonusUpdate(D.getDifficulty());
    L.ptr -> E.EnemyUpdate(D.getDifficulty());
    P.patternChoice( L.ptr -> matrix, X, Y );
    B.bonusPatternChoice( P.getPlatformNumber(),  L.ptr -> matrix, X, Y);
    L.ptr -> E.EnemyPatternChoice( P.getPlatformNumber(), L.ptr -> matrix, X, Y);
    printMap( L.ptr ->matrix );
    H.setHeroPosition( 18,1 );
    H.heroOnScreen();
    D.printData();
}

void World::changeNode( bool direction ) { 
    if( !direction ){ // direction == 0 se hero si sposta all'indietro
        L.ptr = L.ptr -> prec;
        D.reduceLevelNumber();
        printMap(L.ptr ->matrix);
        H.setHeroPosition( 18,39 );
        H.heroOnScreen();
        D.printData();
    } else{
        L.ptr = L.ptr -> next;
        D.riseLevelNumber();
        printMap(L.ptr ->matrix);
        H.setHeroPosition( 18,1 );
        H.heroOnScreen();
        D.printData();
    }
}

void World::addEmptySpace(char m[][40]) {
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 40; j++ ){
            m[i][j] = ' ';
        }
    }
}

void World::printMap(char m[][40]) {
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 40; j++ ){
            cout << m[i][j];
        }
        cout<<endl;
    }
}

void World::leftWall(char m[][40]) {
    for( int i = 1; i < 19; i++ )
        m[i][0] ='|';
}

void World::topDownWall(char m[][40]) {
    for( int i = 1; i < 40; i++){
        m[0][i] = '=';
        m[19][i] = '=';
    }
}

void World::gameover() {
    M.endGame();
    D.printName();
    cout << "\t";
    D.printScore();
    cout << "\t\t";
    D.printLevelNumber();
    cout << endl << endl << "Premere X per uscire." << endl;
    while( getch() != 'x' )
    M.ExitMenu();
}


