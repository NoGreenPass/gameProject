class Bonus{
    protected:
        char skin;
        int x;
        int y;
        bool exist;
    public:
        Bonus();
        void initPosition( int, int );
        char getSkin();
        int getX();
        int getY();
        void setExistence( bool );
        bool getExistence();
};