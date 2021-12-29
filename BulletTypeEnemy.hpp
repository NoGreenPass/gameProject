#include <conio.h>
#include <windows.h>

class BulletTypeEnemy{
    protected:
        short x;
        short y;
    public:
        BulletTypeEnemy();
        void setPosition( short, short );
        void printBullet();
        bool stopBullet( char[][30], bool );
        void moveBullet();
        bool heroHit( short, short );
        short getX();
        short getY();
};