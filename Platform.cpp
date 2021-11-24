#include "Platform.hpp"

Platform::Platform(){
    srand(time(0));
    casualPattern = 1 + rand() % 4; 
}

void Platform::Pattern1( char m[][40], const int x, const int y ){
    for(int i=11; i<14; i++){
        m[18][i] = '=';
    }
    for(int i=30; i<32; i++){
        m[18][i] = '=';
    }
    m[17][14] = '=';
    for(int i=26; i<30; i++){
        m[17][i] = '=';
    }
    m[16][15] = '=';
    m[15][16] = '=';
}
void Platform::Pattern2( char m[][40], const int x, const int y ){
    for(int i=7; i<11; i++){
        m[18][i] = '=';
    }
    for(int i=25; i<28; i++){
        m[18][i] = '=';
    }
    for(int i=4; i<7; i++){
        m[17][i] = '=';
    }
    for(int i=28; i<31; i++){
        m[17][i] = '=';
    }
    for(int i=1; i<4; i++){
        m[16][i] = '=';
    }
    m[16][31] = '=';
    for(int i=32; i<34; i++){
        m[15][i] = '=';
    }
    for(int i=30; i<32; i++){
        m[14][i] = '=';
    }
    for(int i=35; i<40; i++){
        m[14][i] = '=';
    }
    for(int i=22; i<25; i++){
        m[13][i] = '=';
    }
    for(int i=32; i<35; i++){
        m[13][i] = '=';
    }
    for(int i=25; i<32; i++){
        m[12][i] = '=';
    }
}
void Platform::Pattern3( char m[][40], const int x, const int y ){
    for (int i=11; i<13; i++){
        m[18][i] = '=';
    }
    for(int i=20; i<24; i++){
        m[18][i] = '=';
    }
    for(int i=13; i<20; i++){
        m[17][i]  = '=';
    }
}
void Platform::Pattern4( char m[][40], const int x, const int y ){
    for(int i=4; i<7; i++){
        m[18][i] = '=';
    }
    for(int i=7; i<10; i++){
        m[17][i] = '=';
    }
    for(int i=10; i<12; i++){
        m[16][i] = '=';
    }
    for(int i=7; i<10; i++){
        m[15][i] = '=';
    }
    for(int i=10; i<13; i++){
        m[14][i] = '=';
    }
    for(int i=13; i<20; i++){
        m[13][i] = '=';
    }
    for(int i=20; i<22; i++){
        m[12][i] = '=';
    }
    for(int i=18; i<20; i++){
        m[11][i] = '=';
    }
    for(int i=22; i<24; i++){
        m[11][i] = '=';
    }
    for(int i=28; i<36; i++){
        m[11][i] = '=';
    }
    for(int i=14; i<18; i++){
        m[10][i] = '=';
    }
    for(int i=24; i<28; i++){
        m[10][i] = '=';
    }
    for(int i=18; i<20; i++){
        m[9][i] = '=';
    }
    for(int i=22; i<24; i++){
        m[9][i] = '=';
    }
    for(int i=20; i<22; i++){
        m[8][i] = '=';
    }
}

int Platform::PatternChoice( char m[][40], const int x, const int y ){
    switch(casualPattern){
        case 1:
            Pattern1( m, x, y );
            return 1;
            break;
        case 2:
            Pattern2( m, x, y );
            return 2;
            break;
        case 3:
            Pattern3( m, x, y );
            return 3;
            break;
        case 4:
            Pattern4( m, x, y );
            return 4;
            break;
        default:
            return 0;
            break;
    }
}