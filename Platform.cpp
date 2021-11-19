#include "Platform.hpp"

Platform::Platform( int lvl, char m[][40], const int x, const int y ){
    srand(time(0));
    casualPattern = 1 + rand() % 4; 
    PatternChoice( m, x, y );
}

void Platform::Pattern1( char m[][40], const int x, const int y ){
    for(int i=10; i<13; i++){
        m[18][i] = '=';
    }
    for(int i=33; i<35; i++){
        m[18][i] = '=';
    }
    m[17][14] = '=';
    for(int i=25; i<29; i++){
        m[17][i] = '=';
    }
    m[16][16] = '=';
    m[15][18] = '=';
}
void Platform::Pattern2( char m[][40], const int x, const int y ){
    for(int i=10; i<12; i++){
        m[18][i] = '=';
    }
    for(int i=19; i<21; i++){
        m[18][i] = '=';
    }
    for(int i=5; i<8; i++){
        m[18][i] = '=';
    }
    for(int i=23; i<25; i++){
        m[18][i] = '=';
    }
    for(int i=1; i<3; i++){
        m[17][i] = '=';
    }
    for(int i=27; i<29; i++){
        m[17][i] = '=';
    }
    for(int i=31; i<33; i++){
        m[16][i] = '=';
    }
    for(int i=29; i<31; i++){
        m[15][i] = '=';
    }
    for(int i=35; i<40; i++){
        m[15][i] = '=';
    }
    for(int i=20; i<23; i++){
        m[14][i] = '=';
    }
    for(int i=32; i<34; i++){
        m[14][i] = '=';
    }
    for(int i=25; i<32; i++){
        m[13][i] = '=';
    }
}
void Platform::Pattern3( char m[][40], const int x, const int y ){
    for(int i=14; i<20; i++){
        m[17][i]  = '=';
    }
    m[16][10] = '=';
    for(int i=24; i<26; i++){
        m[16][i] = '=';
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
    for(int i=6; i<9; i++){
        m[15][i] = '=';
    }
    for(int i=28; i<36; i++){
        m[15][28] = '=';
    }
    for(int i=10; i<13; i++){
        m[14][i] = '=';
    }
    for(int i=15; i<19; i++){
        m[13][i] = '=';
    }
    for(int i=20; i<22; i++){
        m[12][i] = '=';
    }
    for(int i=17; i<19; i++){
        m[11][i] = '=';
    }
    for(int i=23; i<25; i++){
        m[11][i] = '=';
    }
    for(int i=12; i<16; i++){
        m[10][i] = '=';
    }
    for(int i=26; i<30; i++){
        m[10][i] = '=';
    }
    for(int i=17; i<19; i++){
        m[9][i] = '=';
    }
    for(int i=23; i<24; i++){
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
        case 2:
            Pattern2( m, x, y );
            return 2;
        case 3:
            Pattern3( m, x, y );
            return 3;
        case 4:
            Pattern4( m, x, y );
            return 4;
        default:
            return 0;
    }
}