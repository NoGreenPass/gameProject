#include "Hero.hpp"
#include "BonusType.hpp"
#include "EnemyType.hpp"
#include "BulletType.hpp"
#include "Menu.hpp"
#include "GameData.hpp"
#include "Map.hpp"

#define X 10 
#define Y 30 
#define MAXBONUS 3
#define MAXENEMY 9


class World {
     protected:
        struct Pointers {
            char matrix[X][Y];
            Bonus bonusArray[MAXBONUS];
            Enemy enemyArray[MAXENEMY];
            int counterEnemy;
            Pointers *prec;
            Pointers *next;
        };
        typedef Pointers* ptr;
        struct List{
            ptr head;
            ptr tail;
            ptr ptr;
        };
        ptr p = 0;
        ptr q = 0;
        ptr tmp;
        int counterNode = 0;
        List L;
        GameData D;
        Menu menu;
        BulletTypeHero bulletH;
        int bulletDirection;
        Hero H;
    public:
        World();
        void startGame();
        void userPressA();
        void userPressD();
        void userPressW();
        void userPressS();
        void createAndPrintFirstLevel(); 
        void addNode(); //aggiungere un nodo alla lista (ricordarsi di richiamare Platform)
        void changeNode( bool ); //aggiorna il puntatore al nodo corrente (avanti 1 e indietro 0 )
        void uploadBonus();
        void uploadEnemy();
        void printMap(char [][30]); //stampa la matrice
        void gameover(); //gameover, richiamare il menu per esito finale
};