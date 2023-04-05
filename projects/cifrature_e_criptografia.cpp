#include <iostream>
#include <string.h>
#include <algorithm>
#define dim 10000

using namespace std;

/*
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
char chiaro[dim], select[dim];
int alt, j = 0, n_alf = strlen(alfabeto); //<-- variabili d'appoggio/ottimizzazione
// cesare
char cesare[dim];
// boss
char boss_d[dim];
int boss[dim];
// vigenere
char vigenere[dim], chiave[dim];
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// FUNZIONI :
//  globale
int indice_lettera(char a)
{
    int b = 66; // codice errore (lettera non trovata)

    for (int i = 0; i <= n_alf; i++)
    {
        if (alfabeto[i] == a)
        {
            b = i;
        }
    }
    return b;
}

void registra_chiave(char a[])
{
    cout << "\n\n\n Inserisci la chiave per il criptaggio : ";
    gets(a);
}
// cifratura
void cifratura_cesare() // fixed
{
    for (int i = 0; i < strlen(chiaro); i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        {
            if ((alt + 3) > n_alf)
            {
                cesare[i] = alfabeto[(alt - (n_alf - 3))];
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

void cifratura_del_boss() // fixed
{
    for (int i = 0; i < strlen(chiaro); i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        {
            if ((alt + 3) > n_alf)
            {
                boss[i] = (alt - (n_alf - 3));
            }
            else
            {
                boss[i] = (alt + 3);
            }
        }
        else
        {
            switch (chiaro[i])
            {
            case '?':
                alt = 67;
                break;
            case '.':
                alt = 68;
                break;
            case ',':
                alt = 69;
                break;
            default:
                alt = 70;
                break;
            }

            boss[i] = alt;
        }
    }
}

void cifratura_vigenere() // fixed
{
    registra_chiave(chiave);

    for (int i = 0; i < strlen(chiaro); i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        { // cifratura lettera
            if (alt + indice_lettera(chiave[j]) > n_alf)
            {
                vigenere[i] = alfabeto[alt - (n_alf - indice_lettera(chiave[j]))];
            }
            else
            {
                vigenere[i] = alfabeto[alt + indice_lettera(chiave[j])];
            }
            // aggiornamento posizione chiave
            if (j < (strlen(chiave) - 1))
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
            vigenere[i] = chiaro[i];
        }
    }
}
// decifratura
void decifratura_cesare() // fixed
{
    for (int i = 0; i <= strlen(chiaro); i++)
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
            cesare[i] = chiaro[i];
        }
    }
}

void decifratura_del_boss() // fixed(bypass)
{

    for (int i = 0; i < strlen(chiaro); i++) // (sizeof(boss)/sizeof(boss[0]))  visto che è un array di numeri => numero di elementi = byte totali / bytes per ogni elemento
    {
        alt = boss[i];

        if (alt != 66)
        {
            if ((alt - 3) < 0)
            {
                boss_d[i] = alfabeto[alt + (n_alf - 3)];
            }
            else
            {
                boss_d[i] = alfabeto[alt - 3];
            }
        }
        else
        {
            switch (boss[i])
            {
            case 67:
                boss_d[i] = '?';
                break;
            case 68:
                boss_d[i] = '.';
                break;
            case 69:
                boss_d[i] = ',';
                break;
            default:
                boss_d[i] = ' ';
                break;
            }
        }
    }
}

void decifratura_vigenere() // to check
{
    registra_chiave(chiave);

    int j = 0;

    for (int i = 0; i <= strlen(chiaro); i++)
    {
        alt = indice_lettera(chiaro[i]);

        if (alt != 66)
        { // cifratura lettera
            if (alt + indice_lettera(chiave[j]) > n_alf)
            {
                vigenere[i] = alfabeto[alt + (n_alf - indice_lettera(chiave[j]))];
            }
            else
            {
                vigenere[i] = alfabeto[alt - indice_lettera(chiave[j])];
            }
            // aggiornamento posizione chiave
            if (j < (strlen(chiave) - 1))
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
            vigenere[i] = chiaro[i];
        }
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    cout << "\n Benvenuti nel CIFRATORE AUTOMATICO.\n\n Regole per l'utilizzo: \n\n - Niente maiuscole \n\n - Niente lettere accentate \n\n - Caratteri massimi attuali (spazi e punteggiatura inclusa) " << dim << " \n\n - Buon divertimento.\n\n";
    cout << "\n Specifica se vuoi 'cifrare' o 'decifrare' il messaggio ('c'/'d'): ";
    gets(select);

    cout << "\n Inserisci il testo da elaborare : ";
    // la funzione cin() registra la prima parola fino allo spazio, gets() registra fino all'invio.
    gets(chiaro);

    if (select == "c")
    {
        cout << "\n Il testo in chiaro è : '" << chiaro << "'";
        cifratura_cesare();
        cout << "\n\n --> [cifrario di cesare] : '" << cesare << "'";
        cifratura_del_boss();
        cout << "\n\n --> [cifrario del boss mafioso] : '";
        for (int number : boss)
        {
            cout << number;
        }
        cout << "'";
        cifratura_vigenere();
        cout << "\n --> [cifrario di vigenere] ([verman] se lunghezza chiave = lunghezza testo) : '" << vigenere << "'";
    }
    else if (select == "d")
    {
        cout << "\n Il testo cifrato è : '" << chiaro << "'";
        decifratura_cesare();
        cout << "\n\n --> [cifrario di cesare] : '" << cesare << "'";
        decifratura_del_boss();
        cout << "\n\n --> [cifrario del boss mafioso] : '" << boss_d << "'";
        decifratura_vigenere();
        cout << "\n --> [cifrario di vigenere] ([verman] se lunghezza chiave = lunghezza testo) : '" << vigenere << "'";
    }
    else
    {
        cout << "\n\n\n Error: input command error 01";
    }
    return 0;
}