// ALGORITMO_Horner 
#include <iostream>
using namespace std;
// prototipi

int main()
{
	int Vet[100], X0, N, horner;
		//grado polinomio
	cout << "Inserisci il grado del polinomio: ";
	cin >> N;
		//leggi x
	cout << endl << "Inserisci il valore di x: "; 
	cin >> X0;
		//carica coefficienti
	cout << endl << "Inserisci i coefficienti da a0 ... an" << endl;
	
	for(int i = 0; i <= N; i++){
		
		cout << endl << "Inserisci il " << i << " coefficiente: ";
		cin >> Vet[i];	
	}
		//metodo di horner
	horner = Vet[N];
	
	for(int i=1; i<=N; i++){
		
		horner = horner*X0+Vet[N-i];

		// p(x)=x{x[x(3x + 4) - 2] + 5} - 4	 => p(x)=x{x[xy - 2] + 5} - 4 => p(x)=x{xz + 5} - 4 => p(x)=xk - 4 => risultato
		//moltiplico l'ultimo coefficiente per il valore di x e gli addiziono il penultimo ..
	}
	 	//esposizione risultato
	cout<<endl<<"Valore del polinomio = "<< horner <<endl;
	
	system("pause");
}









