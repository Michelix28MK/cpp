#include <iostream>
#include <string.h>
#include <algorithm>
#define dim 10000

using namespace std;

/**
 * CIFRARIO DI CESARE :
 * il cifrario di cesare sostituisce le lettere con la terza a seguire nell' alfabeto (sostituzione/scorrimento)
 *
 * CIFRARIO DEL BOSS DELLA MAFIA :
 * il cifrario del boss mafioso sostituisce le lettere con il numero alfabetico addizionato di tre
 *
 * CIFRARIO DI VIGENERE :
 * il cifrario di vigenere sostituisce la lettera con la lettera corrispondente alla somma tra l'indice originale e la lettera della parola chiave
 * 
 * CIFRARIO DI VERNAM :
 * il cifrario di vernam funziona come il cifrario di vigenere con l'imposizione che la chiave deve essere lunga come la frase da nascondere
 */
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// VARIABILI :
//  globali
char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char chiaro[dim], cifrato[dim];
int alt, n_alf = strlen(alfabeto), n_ch = strlen(chiaro); //<-- variabili d'appoggio/ottimizzazione
// cesare
char cesare[dim];
// boss
char boss[dim];
// vigenere
char vigenere[dim], chiave[dim];
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// FUNZIONI :
//  globale
int indice_lettera(char a)
{
    int b = 66;

    for (int i = 0; i < n_alf; i++)
    {
        if (alfabeto[i] == a)
        {
            b = i;
        }
    }
    return b;
}

void registra_converti_chiave(char chiave)
{
    cout << "\n\n Inserisci la chiave per il criptaggio : ";
    gets(chiave);

    for (int i = 0; i <= strlen(chiave); i++)
    {
        chiave[i] = indice_lettera(chiave[i]);
    }
}
// cifratura
void cifratura_cesare()
{
    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        {
            if (alt + 3 >= n_alf)
            {
                cesare[i] = alfabeto[(alt - n_alf + 3)];
            }
            else
            {
                cesare[i] = alfabeto[alt + 3];
            }
        }
        else
        {
            cesare[i] = chiaro[i];
        }
    }
}

void cifratura_del_boss()
{

    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro);

        if (alt != 66)
        {
            if (alt + 3 >= n_alf)
            {
                boss[i] = alt - n_alf + 3;
            }
            else
            {
                boss[i] = alt + 3;
            }
        }
        else
        {
            boss[i] = chiaro[i];
        }
    }
}

void cifrario_vigenere()
{
    registra_converti_chiave();

    int j = 0;

    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        { // cifratura lettera
            if (alt + (int)chiave[j] > n_alf)
            {
                vigenere[i] = alfabeto[alt - n_alf + (int)chiave[j]];
            }
            else
            {
                vigenere[i] = alfabeto[alt + (int)chiave[j]];
            }
            // aggiornamento posizione chiave
            if (j < strlen(chiave))
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        else
        {
            vigenere[i] = cifrato[i];
        }
    }
}
// decifratura
void decifratura_cesare()
{
    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        {
            if (alt - 3 < 0)
            {
                cesare[i] = alfabeto[(alt + n_alf - 3)];
            }
            else
            {
                // cout << endl << i <<" lettera è " << alfabeto[alt - 3]<<endl;
                cesare[i] = alfabeto[alt - 3];
            }
        }
        else
        {
            cesare[i] = cifrato[i];
        }
    }
}

void decifratura_del_boss()
{

    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro);

        if (alt != 66)
        {
            if (alt - 3 <= 0)
            {
                boss[i] = alt - 24;
            }
            else
            {

                boss[i] = alt + 3;
            }
        }
        else
        {
            boss[i] = chiaro[i];
        }
    }
}

void decifratura_vigenere()
{
    registra_converti_chiave();

    int j = 0;

    for (int i = 0; i <= n_ch; i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        { // cifratura lettera
            if (alt - (int)chiave[j] < 0)
            {
                vigenere[i] = alfabeto[alt + n_alf - (int)chiave[j]];
            }
            else
            {
                vigenere[i] = alfabeto[alt - (int)chiave[j]];
            }
            // aggiornamento posizione chiave
            if (j < strlen(chiave))
            {
                j++;
            }
            else
            {
                j = 0;
            }
        }
        else
        {
            vigenere[i] = cifrato[i];
        }
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    cout << "\n Benvenuti nel CIFRATORE AUTOMATICO.\n\n Regole per l'utilizzo: \n\n - Niente maiuscole \n\n - Niente lettere accentate \n\n - Caratteri massimi attuali (spazi e punteggiatura inclusa) " << dim << " \n\n - Buon divertimento.\n\n";
    cout << "\n Inserisci la frase da cifrare: " << endl;
    // la funzione cin() registra la prima parola fino allo spazio, gets() registra fino all'invio.

    gets(chiaro);

    cout << "\n La tua frase è in chiaro è : '" << chiaro << "'";
    cifratura_cesare();
    cout << "\n\n --> [cifrario di cesare] : '" << cesare << "'";
    cifratura_del_boss();
    cout << "\n\n --> [cifrario del boss mafioso] : '" << boss << "'";
    cifrario_vigenere();
    cout << "\n\n --> [cifrario di vigenere] : '" << vigenere << "'";

    return 0;
}