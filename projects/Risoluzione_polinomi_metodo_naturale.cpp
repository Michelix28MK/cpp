//Metodo_Naturale
#include <iostream>
#include <cmath>
using namespace std;

void Carica_Coefficienti(int vettore[], int dim){

    cout<<"Inserisci i coefficienti da a0...an"<<endl;
    
    for(int i=0; i<=dim; i++){
    	cout<<"inserisci il coefficente di "<<i <<" grado: ";
    	cin>>vettore[i];
	}
}

int Grado_Polinomio(){
	
    int grado;
    cout<<"Inserisci il grado del polinomio: ";
    cin>>grado;
    
    return grado;
}

int Leggi_x(){

    int x;
    cout <<"Inserisci il valore di x: ";
    cin>>x;
    
    return x;
}

int refix(int grado, int vettore[], int valore_x){
	int risultato= vettore[0];
	
	for(int i=1; i<=grado; i++){
		risultato = risultato + pow(valore_x,i) * vettore[i];
	}
	return risultato;
}

// polinomio naturale 
int main()
{   
    int Vet[100],X0, N, Rn;
    
    N=Grado_Polinomio();
    
    Carica_Coefficienti(Vet,N);
    
    X0=Leggi_x();
    
    Rn=refix(N, Vet, X0);
    
    cout << "Valore del polinomio =" << Rn << endl;
    system("pause");
}
