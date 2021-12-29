class Bullet{
    protected:
        int x;
        int y;
        int range;
    public:
        Bullet();
        void setPosition( int, int );
        void moveBullet( int );
        void spawnBullet( char [][30] );
        void cancelBullet( char[][30] );
        bool stopBullet( char [][30] );
        int getX();
        int getY();
};