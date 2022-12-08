#include <iostream>
#include <math.h>

#define MAX 25

using namespace std;

int m[MAX][MAX], c, riga,col,norma1=0,normainf=0;

int main ()
{
	cout<<"Iserisci l'ordine della matrice: ";
	cin>>c;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{	
			cout << endl << "Inserisci il numero alla " << i+1 << " riga e "<< j+1 <<" colonna : ";
			cin>>m[i][j];
		}
	}

		//calcolo della norma infinito
	for (int i=0;i<c;i++)
	{
		riga=0;

		for (int j=0;j<c;j++){

			riga+=abs(m[i][j]);
		}

		if(normainf<riga){

			normainf=riga;
		}
	}

		//calcolo della norma 1

	for(int i=0;i<c;i++)
	{
		col=0;

		for (int j=0;j<c;j++){

			col +=abs(m[j][i]);
		}

		if (norma1<col) {
			
			norma1=col;
		}
	}

	cout<<"norma 1: "<<norma1<<endl<<"norma infinito: "<<normainf<<endl;

	system("pause");

return 0;
}

/**
 * Come per il programma precedente, per comodità di recupero scrivi le variabili fuori dal main() e anche qui la Void() è pressochè inutile ma l'esercizio è impostato così perciò è inutile che te lo stravolga. Ricordati L'INDENTAZIONE!
 * 
 * In ogni caso l'esercizio richiedeva solo ce tu caricassi la matrice con i valori per l'elaborazione.
 * 
 * Se hai qualche domanda fammi uno squillo omandami un messaggio.
 * 
 * By Michel :-)
*/