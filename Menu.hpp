#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

class Menu{
    protected:
        char username[20]; // Nome Utente che inizia una partita
        char skin; // Immagine stampata a schermo del personaggio
        int count = 1; // Contatore che riconosce il numero della pagina del menu
    public:
        Menu();

        void startMenu();
        void DisplayMessage1(); // Stampa messaggio di benvenuto ( chiamata all'avvio del gioco )
        void DisplayMessage2(); // Richiede di inserire il nome utente ( username )
        void DisplayMessage3(); // Mostra le regole del gioco ( versione semplice delle regole vere e proprie )
        void DisplayMessage4(); // Scelta del personaggio
         // Funzioni ausiliarie a DisplayMessage 4 :
        bool setSkinNumber(); // Prende in input il numero da tastiera e assegna il corrispondente carattere a skin
        void DisplayMessage5(); // Pagina Autori

        void DefaultDisplayMessage( short, short ); // Stampa scelta: Exit, Back, Next
        void DynamicMenu( int ) ;
        void DisplayNumber(); // Associa al valore del count il DisplayMessage da stampare
        void ExitMenu();

        void endGame();
        
        char getPlayerSkin(); // return della skin 
        char *getPlayerName() ; // return del nome giocatore
};