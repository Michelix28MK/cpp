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

    for (int i = 0; i < Vet.size(); i++)    //.size() può essere utilizzato per lavorare con questa versione di vettori
    {
        cout<<Vet[i]<<"\t";
    }

    for (auto i = 0; i < Vet.size()-1; i++)
    {
        for (auto j = i+1; j < Vet.size(); j++)
        {
            if(Vet[i] < Vet[j]){ //decrescenza
                c = Vet[i];
                Vet[i] = Vet[j];
                Vet[j] = c;
            }
        }
    }
    cout<<"\n vettore ordinato \n";

    for (int i = 0; i < Vet.size(); i++)
    {
        cout<<Vet[i]<<"\t";
    }

    for (auto i = 0; i < Vet.size()-1; i++)
    {
        for (auto j = i+1; j < Vet.size(); j++)
        {
            if(Vet[i] > Vet[j]){ //crescenza
                c = Vet[i];
                Vet[i] = Vet[j];
                Vet[j] = c;
            }
        }
    }
    cout<<"\n vettore ordinato \n";

    for (int i = 0; i < Vet.size(); i++)
    {
        cout<<Vet[i]<<"\t";
    }
    
    return 0;
}