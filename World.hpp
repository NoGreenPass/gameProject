#include "Hero.hpp"
#include "Bonus.hpp"
#include "Menu.hpp"
#include "GameData.hpp"
#include "Platform.hpp"

/* #define X = 20; */
/* #define Y = 40; */
const int X = 20;
const int Y = 40;

class World {
     protected:
        struct Map {
            char matrix[X][Y];
            Map *prec;
            Map *next;
        };
        typedef Map* ptrMap;
        struct List{
            ptrMap head;
            ptrMap tail;
            ptrMap ptr;
        };
        ptrMap p = 0;
        ptrMap q = 0;
        ptrMap tmp;
        int counterNode = 0;
        List L;
        GameData D;
        Menu M;
        /* Bullet B; */
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
        void addEmptySpace(char [][40]); //inserisce nella matrice tutti gli spazi vuoti
        void leftWall(char [][40]); //crea il muro di sinistra
        void topDownWall(char [][40]); //crea i muri sopra e sotto
        void printMap(char [][40]); //stampa la matrice
        void updateData(); //aggiorna i dati modificati
        void gameover(); //gameover, richiamare il menu per esito finale
};