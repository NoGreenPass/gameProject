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
        char getSkin();
        int getX();
        int getY();
        void setExistence( bool );
        bool getExistence();
        int getRange();
        int getDamage();
        int getBulletDamage();
        int getLife();
        void reduceLife( int );
};