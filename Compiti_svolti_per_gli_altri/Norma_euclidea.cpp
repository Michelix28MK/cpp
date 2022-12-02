#include <iostream>
#include <math.h>

using namespace std;

int s=0, normae, vet[10], n=10;

int main ()
{
    carica_vettore();

    for (int i=0; i<n; i++){

        s+=vet[i]*vet[i];
    }

    normae=sqrt(s);

    cout << endl << "Norma euclidea: " << normae << endl;

    system("pause");

    return 0;
}

void carica_vettore(){

    for (int i = 0; i < n; i++)
    {
        cout << endl << "inserisci il "<<i+1<<" numero: ";
        cin>>vet[n];
    }
}
/**
 * Le variabili devi tenerle al difuori del main() perchè possano essere visualizzate dalla Void()
 * 
 * Ricordati che l'indentazione e la spazziatura sono importanti e non sono opzionali.
 * 
 * Se volessi essere preciso la procedura non ti servirebbe nemmeno e potresti copiare il codice direttamente 
 * nel codice
 * 
 * Se hai domande chiedi pure.
 * 
 * By Michele :-)
*/