/* #include "Bullet.hpp" */
#include <windows.h>
#include <conio.h>

class BulletTypeHero{
    protected:
        int x;
        int y;
        const int range = 3;
    public:
        BulletTypeHero( int, int );
        void printBullet();
        bool stopBullet( char[][30]);
        void moveBullet( int );
        bool enemyHit( char[][30] );
        int getRange();
        int getX();
        int getY();
};