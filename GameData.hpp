#include <windows.h>
#include <string.h>
#include <iostream>
using namespace std;

class GameData{
    public:
        GameData(); // Inizializza i dati gioco con valori di default

        int getLevelNumber();
        void riseLevelNumber(); // Incrementa il numero del livello ( sotto opportune condizioni )

        void printData(); // Stampa dati gioco in una posizione predefinita dello schermo

        int getLifePoints();
        void riseLifePoints( int ); // Incrementa i punti vita ( sotto opportune condizioni )
        void reduceLifePoints( int ); // Diminuisce i punti vita ( sotto opportune condizioni )

        void riseScore( int ); // Incrementa il punteggio ( sotto opportune condizioni )
        void reduceScore( int ); // Diminuisce il punteggio ( sotto opprtune condizioni )
     
        void printDifficulty(); // Stampa il livello di difficolta' ( vista utente )
        int getDifficulty(); // return difficulty

        void setName( char [] ); // Imposta il nome giocatore
     
    protected:
        char name[20]; // Nome giocatore
        int levelNumber; // Numero livello
        int lifePoints; // Punti vita
        int score; // Punteggio
        int difficulty; // Livello di difficolta'
} ;