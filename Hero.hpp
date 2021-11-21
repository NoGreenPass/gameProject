#include <conio.h>
#include <windows.h>

class Hero{
    protected:
        char skin;
        short row; 
        short column; 
    public:
        Hero();
        void setHeroPosition( short, short );

        void isMovingRight(); 
        void isMovingLeft();
        void isMovingUp( bool );
        void isMovingDown( bool );
        void heroOnScreen();

        void setSkin( char );
        char getSkin();
        short getRowPosition();
        short getColumnPosition();
};