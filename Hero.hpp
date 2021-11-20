#include <conio.h>
#include <windows.h>

class Hero{
    public:
        Hero();

        void setSkin( char );
        char getSkin();
        void setHeroPosition( short, short );
        short getRowPosition();
        short getColumnPosition();

        void isMovingRight(); 
        void isMovingLeft();
        void isMovingUp( bool );
        void isMovingDown( bool );

        void heroOnScreen();
    protected:
        char skin;
        short row; 
        short column; 
};