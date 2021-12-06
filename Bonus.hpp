#include <cstdlib>
#include <time.h>

class Bonus{
    public:
        Bonus();
        void bonusPattern1 (char [][40], const int, const int);
        void bonusPattern2 (char [][40], const int, const int);
        void bonusPattern3 (char [][40], const int, const int);
        void bonusPattern4 (char [][40], const int, const int);
        void bonusPattern5 (char [][40], const int, const int);
        char bonusChoice (); 
        void bonusPatternChoice (int, char [][40], const int, const int);
        void bonusUpdate (int);
        int getPoints ();
        int getHealth ();
        void cancelBonus (char [][40], const int, const int, int, int);
    protected:
        int casualBonus;
        int pointsEarned;
        int healthEarned;
};