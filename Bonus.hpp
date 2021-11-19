#include <cstdlib>
#include <time.h>

class Bonus{
    public:
        Bonus(int);
        void BonusPattern1 (char [][40], const int, const int);
        void BonusPattern2 (char [][40], const int, const int);
        void BonusPattern3 (char [][40], const int, const int);
        void BonusPattern4 (char [][40], const int, const int);
        char BonusChoice (); 
        void getChoice (int, char [][40], const int, const int);
        int getPoints ();
        int getHealth ();
    protected:
        int casualBonus;
        int pointsEarned;
        int healthEarned;
};