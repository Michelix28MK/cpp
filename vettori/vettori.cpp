#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> Vet{ 3, 15 , 78 , 14 ,11};
    int c;

    cout<<"Vettore di partenza \n";

    for (int i = 0; i < Vet.size(); i++)    //.size() può essere utilizzato per lavorare con questa versione di vettori
    {
        cout<<Vet[i]<<"\t";
    }

    Vet.pop_back(); //toglie l'ultimo elemento
    Vet.push_back(21);  //aggiunge all'ultima posizione  

    cout<<"\n Vettore modificato \n";

    for (int i = 0; i < Vet.size(); i++) //.size() può essere utilizzato per lavorare con questa versione di vettori
    {
        cout<<Vet[i]<<"\t";
    }

    return 0;
}