#include "Bullet.hpp"

class BulletTypeHero: public Bullet{
    public:
        BulletTypeHero();
        bool enemyHit( char [][30] );
        int getRange();
};