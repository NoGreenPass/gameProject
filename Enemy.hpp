#include <cstdlib>
#include <windows.h>
#include <time.h>

#define MAX_ENEMY_NUMBER 9

class Enemy{
        protected:
            int casualEnemy;
            int difficulty;
            int countEnemy;
            struct enemyStats{
                char skin;
                int healt;
                int damage;
                int range;
                int x = -1;
                int y = -1;
                bool death;
                bool direction;
            };
        public:
            enemyStats enemyArray[MAX_ENEMY_NUMBER];
            Enemy();
            int EnemyIsMoving(char [][40], const int, const int, short, short );
            void EnemyPattern1(char [][40], const int, const int);
            void EnemyPattern2(char [][40], const int, const int);
            void EnemyPattern3(char [][40], const int, const int);
            void EnemyPattern4(char [][40], const int, const int);
            void EnemyPattern5(char [][40], const int, const int);
            char EnemyChoice();
            void EnemyPatternChoice(int, char [][40], const int, const int);
            void EnemyUpdate(int);
            void setCount();
            void CancelEnemy(char [][40], const int, const int, short, short);
            void chargheEnemyArray( char [][40], const int, const int );
}; 