#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * il cifrario di cesare sostituisce le lettere con la terza a seguire nell' alfabeto
 */
const char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // 26

/**
 * ricercare a partire dalla lettera della parola da cifrare la sua posizione nell'alfabeto e sostituirla con la 3 lettera a seguire.
 */
char chiaro[200], cifrato[200];
int help;

int main()
{
    cout << "inserisci la parola da cifrare: " << endl;
    // la funzione cin() registra la prima parola fino allo spazio, gets() registra fino all'invio.

    gets(chiaro);

    cout << "\n La tua frase è : '" << chiaro << "' e verrà cifrata tramite il cifrario di cesare.\n";
    cifratura_cesare();
    cout << "\n La frase cifrata è : '" << cifrato << "' !";

    return 0;
}

void cifratura_cesare()
{
    for (int i = 0; i < 26; i++)
    {
        help = alfabeto.find(chiaro[i]);

        if (help != string::npos) // la punteggiatura e gli spazzi vengono ignorati
        {
            if (help + 3 > 25)
            {
                cifrato[i] = alfabeto[(help + 3) - 26];
            }

            cifrato[i] = alfabeto[help + 3];
        }
    }
}
// si utilizzano le funzioni delle stringhhe per elaborarle e confrontarle e sostituirle