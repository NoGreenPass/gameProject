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
                int x;
                int y;
                bool direction = false;
            };
            enemyStats enemyArray[MAX_ENEMY_NUMBER];
        public:
            Enemy();
            void EnemyIsMoving(char [][40], const int, const int );
            void EnemyPattern1(char [][40], const int, const int);
            void EnemyPattern2(char [][40], const int, const int);
            void EnemyPattern3(char [][40], const int, const int);
            void EnemyPattern4(char [][40], const int, const int);
            void EnemyPattern5(char [][40], const int, const int);
            char EnemyChoice();
            void EnemyPatternChoice(int, char [][40], const int, const int);
            void EnemyUpdate(int);
            void setCount();
            void CancelEnemy(char [][40], const int, const int, int, int);
            void chargheEnemyArray( char [][40], const int, const int );
}; 