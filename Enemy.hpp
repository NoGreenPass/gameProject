#include <cstdlib>
#include <time.h>

class Enemy{
        public:
            Enemy(int);
            void EnemyIsMoving();
            void EnemyPattern1(char [][40], const int, const int);
            void EnemyPattern2(char [][40], const int, const int);
            void EnemyPattern3(char [][40], const int, const int);
            void EnemyPattern4(char [][40], const int, const int);
            char EnemyChoice();
            void EnemyPatternChoice(int, char [][40], const int, const int);
        protected:
            int casualEnemy;
            int health;
            int damage;
};