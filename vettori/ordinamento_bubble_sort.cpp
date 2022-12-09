#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    vector<int> Vet{ 3, 15 , 78 , 14 ,11};
    int margine = 0, Us, temp;
    bool scambio = false; 

    cout<<"Vettore iniziale: ";
    for (auto &&i : Vet)
    {
        cout << i << " ";
    }
    
    do
    {   
        scambio = false;
        for (auto i = Vet.size()-1; i < margine ; i--)
        {
            if (Vet[i]< Vet[i-1])
            {
                temp = Vet[i];
                Vet[i] = Vet[i-1];
                Vet[i-1] = temp;
                Us = i;
                scambio = true;
            }
        } 
        margine = Us;     
    } while (scambio != false);

    cout<<"Vettore finale: ";
    for (auto &&i : Vet)
    {
        cout << i<< " ";
    }

    return 0;
}