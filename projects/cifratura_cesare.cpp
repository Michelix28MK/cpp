#include <iostream>
#include <string.h>
#include <algorithm>
#define dim 10000

using namespace std;

/**
 * CIFRARIO DI CESARE :
 * il cifrario di cesare sostituisce le lettere con la terza a seguire nell' alfabeto
 *
 * CIFRARIO :
 *  blah blah
 */
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//VARIABILI:
//globali
char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char chiaro[dim], cifrato[dim], decifrato[dim];
int alt; //<-- variabile d'appoggio
//cifrario di cesare
// non necessarie
//cifrario a chiave privata
char private_key[dim];
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//FUNZIONI:
//globale
int indice_lettera(char a)
{
    int b = 66;

    for (int i = 0; i < strlen(alfabeto); i++)
    {
        if (alfabeto[i] == a)
        {
            // cout << alfabeto[i] << "=" << a << endl;
            b = i;
        }
    }
    return b;
}
//cifrario di cesare
void cifratura_cesare()
{
    for (int i = 0; i <= strlen(chiaro); i++)
    {
        alt = indice_lettera(chiaro[i]);

        // cout << i << " lettera " << alt << " posizione \n";
        if (alt != 66)
        {
            if (alt + 3 >= 26)
            {
                cifrato[i] = alfabeto[(alt - 24)];
            }
            else
            {

                cifrato[i] = alfabeto[alt + 3];
            }
        }
        else
        {
            cifrato[i] = chiaro[i];
        }
    }
}

void decifratura_cesare()
{
    for (int i = 0; i <= strlen(cifrato); i++)
    {
        alt = indice_lettera(cifrato[i]);

        if (alt != 66)
        {
            if (alt - 3 < 0)
            {
                decifrato[i] = alfabeto[(alt + 24)];
            }
            else
            {
                // cout << endl << i <<" lettera è " << alfabeto[alt - 3]<<endl;
                decifrato[i] = alfabeto[alt - 3];
            }
        }
        else
        {
            decifrato[i] = cifrato[i];
        }
    }
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    cout << "\n Benvenuti nel CIFRATORE AUTOMATICO.\n\n Regole per l'utilizzo: \n\n - Niente maiuscole \n\n - Niente lettere accentate \n\n - Caratteri massimi attuali (spazi e punteggiatura inclusa) " << dim <<" \n\n - Buon divertimento.\n\n";
    cout << "\n Inserisci la frase da cifrare: " << endl;
    // la funzione cin() registra la prima parola fino allo spazio, gets() registra fino all'invio.

    gets(chiaro);

    cout << "\n La tua frase è in chiaro è : '" << chiaro << "' --> [cifrario di cesare]\n";
    cifratura_cesare();
    cout << "\n La frase cifrata è : '" << cifrato << "' !";
    decifratura_cesare();
    cout << "\n La frase decifrata è : '" << decifrato << "' !";

    return 0;
}