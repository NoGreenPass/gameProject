class Enemy{
    protected:
        char skin;
        int x;
        int y;
        int life;
        int damage;
        int bulletDamage;
        int bulletRange;
        bool exist;
    public:
        Enemy();
        void initPosition( int, int );
        void cancelEnemy( char [][30] );
        char getSkin();
        int getX();
        int getY();
        bool getExistence();
        int getRange();
        int getDamage();
        int getBulletDamage();
        int getLife();
        void reduceLife( char [][30], int );
};