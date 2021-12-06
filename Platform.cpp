#include "Platform.hpp"

Platform::Platform(){
    srand(time(0));
    casualPattern = 1 + rand() % 5; 
}

void Platform::Pattern1( char m[][40], const int x, const int y ){
    for(int i=11; i<14; i++){
        m[18][i] = '=';
    }
    for(int i=30; i<32; i++){
        m[18][i] = '=';
    }
    for(int i=14; i<16; i++){
        m[17][i] = '=';
    }
    for(int i=26; i<30; i++){
        m[17][i] = '=';
    }
    for (int i=16; i<18; i++){
        m[16][i] = '=';
    }
    for (int i=18; i<20; i++){
        m[15][i] = '=';
    }
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
    for (int i=8; i<11; i++){
        m[17][i] = '=';
    }
    for(int i=13; i<20; i++){
        m[17][i]  = '=';
    }
    for (int i=24; i<28; i++){
        m[17][i] = '=';
    }
    for (int i=31; i<34; i++){
        m[17][i] = '=';
    }
    for (int i=5; i<8; i++){
        m[16][i] = '=';
    }
    for (int i=28; i<31; i++){
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

void Platform::Pattern5(char m[][40], const int x, const int y){
    for(int i=7; i<10; i++){
        m[18][i] = '=';
    }
    for(int i=20; i<24; i++){
        m[18][i] = '=';
    }
    for(int i=26; i<29; i++){
        m[18][i] = '=';
    }
    for(int i=4; i<7; i++){
        m[17][i] = '=';
    }
    for(int i=24; i<26; i++){
        m[17][i] = '=';
    }
    for(int i=29; i<31; i++){
        m[17][i] = '=';
    }
    for(int i=7; i<10; i++){
        m[16][i] = '=';
    }
    for(int i=31; i<33; i++){
        m[16][i] = '=';
    }
    for(int i=10; i<13; i++){
        m[15][i] = '=';
    }
    for(int i=29; i<31; i++){
        m[15][i] = '=';
    }
    for(int i=13; i<16; i++){
        m[14][i] = '=';
    }
    for(int i=31; i<33; i++){
        m[14][i] = '=';
    }
    for(int i=11; i<13; i++){
        m[13][i] = '=';
    }
    for(int i=33; i<36; i++){
        m[13][i] = '=';
    }
}

int Platform::patternChoice( char m[][40], const int x, const int y ){
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
        case 5:
            Pattern5( m, x, y );
            return 5;
            break;
        default:
            return 0;
            break;
    }
}