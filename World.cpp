#include "World.hpp"

World::World() {
    M.startMenu();
    H.setSkin( M.getPlayerSkin() );
    D.setName(M.getPlayerName());
}

void World::createAndPrintFirstLevel(){
    counterNode = 0;
    D.riseLevelNumber();
    tmp = new Map;
    addEmptySpace(tmp->matrix);
    leftWall(tmp->matrix);
    topDownWall(tmp->matrix);
    tmp -> prec = p;
    q = tmp;
    p = tmp;	
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;  
    Platform P(1,tmp->matrix,0,0);
    Bonus B = Bonus (D.getDifficulty());
    B.getChoice(P.PatternChoice( tmp -> matrix, X, Y ), tmp -> matrix, X, Y);
    printMap(tmp ->matrix);
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
    putch( H.getSkin() );
    D.printData();
}

void World::addNode() {
    counterNode++;
    D.riseLevelNumber();
    tmp = new Map;
    addEmptySpace(tmp->matrix);
    topDownWall(tmp->matrix);
    tmp -> prec = p;
    p->next = tmp;
    p = tmp;
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;
}

void World::changeNode( bool direction ) {
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
    for( int i = 0; i < 19; i++ )
        m[i][0] ='|';
}

void World::topDownWall(char m[][40]) {
    for( int i = 0; i < 40; i++){
        m[0][i] = '=';
        m[19][i] = '=';
    }
}

void World::updateData() {
}

void World::gameover() {
}

void World::startGame() {
    system("cls");
    createAndPrintFirstLevel();
    int key;
    while( (key = _getch()) != 'x' && D.getLifePoints() > 0 ){
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
        switch( key ){
            case 'A':
            case 'a':
                printMap( p -> matrix );
                H.heroOnScreen();
                userPressA();
                break; 
            case 'D':
            case 'd': 
                printMap( p -> matrix );
                H.heroOnScreen();
                userPressD();
                break;
            case 'W':
            case 'w':
                printMap( p -> matrix );
                H.heroOnScreen();
                userPressW();
                break;
            case 'S':
            case 's':
                printMap( p -> matrix );
                H.heroOnScreen();
                userPressS();
                break; 
            default: 
                break;
        }
    }
}

void World::userPressA(){
    if( H.getColumnPosition() != 1 && p -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] != '=' )
        if( p -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] == '=' )
            H.isMovingLeft();
    // TODO: Aggiungere casi in cui hero entra in contatto con nemici o bonus
    // TODO: Aggiungere chiamata a funzioni di cambio nodo con opportune condizioni
}

void World::userPressD(){
    if( H.getColumnPosition() != 39 &&  p -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] != '=' )
        if( p -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] == '=' )
            H.isMovingRight();
    // TODO: Aggiungere casi in cui hero entra in contatto con nemici o bonus
    // TODO: Aggiungere chiamata a funzioni di cambio nodo con opportune condizioni
}

void World::userPressW(){ 
    if(  H.getColumnPosition() != 39 && p -> matrix[H.getRowPosition()][H.getColumnPosition() + 1] == '=')
        H.isMovingUp(1);
    else if( H.getColumnPosition() != 1 &&  p -> matrix[H.getRowPosition()][H.getColumnPosition() - 1] == '=')
        H.isMovingUp(0);
}

void World::userPressS(){
        if(  H.getRowPosition() != 18 && p -> matrix[H.getRowPosition()+1][H.getColumnPosition()+1] != '='){
            if( p -> matrix[H.getRowPosition()+2][H.getColumnPosition()+1] != '=' ){
                short tmp = H.getColumnPosition() + 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(17, tmp );
                H.isMovingDown(1);
            } else H.isMovingDown(1);
        }
        else if( H.getRowPosition() != 18 &&  p -> matrix[H.getRowPosition()+1][H.getColumnPosition()-1] != '='){
            if( p -> matrix[H.getRowPosition()+2][H.getColumnPosition()-1] != '=' ){
                short tmp = H.getColumnPosition() - 1;
                SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {H.getColumnPosition(),H.getRowPosition()});
                putch(' ');
                H.setHeroPosition(17, tmp );
                H.isMovingDown(0);
            } else H.isMovingDown(0);
        }
}

