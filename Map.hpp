// Map - Update matrix with level patterns
// X - Possible enemy location
// Y - Possible bonus location

#include <cstring>
#include <stdlib.h>
#include <time.h>

#define MAP_DIMENSION 300 // 10 x 30

class Map{
    protected:
        char pattern0[MAP_DIMENSION];
        char pattern1[MAP_DIMENSION];
        char pattern2[MAP_DIMENSION];
        char pattern3[MAP_DIMENSION];
        char pattern4[MAP_DIMENSION];
        char heroSkin;
    public:
        Map();
        // Initialize Pattern
        void initPattern();
        // Initialize level
        void initLevel( char [][30] );
};