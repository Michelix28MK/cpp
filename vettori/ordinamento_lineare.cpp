#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> Vet{ 3, 15 , 78 , 14 ,11};
    int c;

    cout<<"\n il vettore iniziale: ";

    for (auto &&i : Vet)
    {
        cout<<i<<" ";
    }
    
    //ordinamento lineare

    for (auto i = 0; i < Vet.size()-1; i++) 
    {
        for (auto j = i+1; j < Vet.size(); j++)
        {
            if(Vet[i] < Vet[j])
            { //decrescenza
                c = Vet[i];
                Vet[i] = Vet[j];
                Vet[j] = c;
            }
        }
    }

    for (auto i = 0; i < Vet.size()-1; i++)
    {
        for (auto j = i+1; j < Vet.size(); j++)
        {
            if(Vet[i] > Vet[j])
            { //crescenza
                c = Vet[i];
                Vet[i] = Vet[j];
                Vet[j] = c;
            }
        }
    }

    for (auto &&i : Vet) //foreach in c++
    {
        cout<<i<<" ";
    }

    cout<<"\n";

    return 0;
}