#include <cstdlib>
#include <time.h>

class Platform{
    public:
        Platform(); // assegna intero casuale al dato membro casualPattern

        // Funzione membro pattern carica nella matrice le strutture del pattern specifico
        void Pattern1( char [][40], const int, const int );
        void Pattern2( char [][40], const int, const int );
        void Pattern3( char [][40], const int, const int );
        void Pattern4( char [][40], const int, const int );

        int PatternChoice(  char [][40], const int, const int ); // Sceglie tra i pattern quale caricare sulla matrice tramite valore casuale
     protected:
        int casualPattern; // Variabile intera casuale che determina il pattern di superfici da stampare
};