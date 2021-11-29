#include <cstdlib>
#include <time.h>

class Bonus{
    public:
        Bonus();
        void BonusPattern1 (char [][40], const int, const int);
        void BonusPattern2 (char [][40], const int, const int);
        void BonusPattern3 (char [][40], const int, const int);
        void BonusPattern4 (char [][40], const int, const int);
        char BonusChoice (); 
        int BonusPatternChoice (int, char [][40], const int, const int);
        void BonusUpdate (int);
        int getPoints ();
        int getHealth ();
        void CancelBonus (char [][40], const int, const int, int, int);
    protected:
        int casualBonus;
        int pointsEarned;
        int healthEarned;
};