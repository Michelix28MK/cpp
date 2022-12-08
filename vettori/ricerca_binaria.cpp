#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> Vet{ 3, 15 , 78 , 14 ,11, 21, 1, 2, 18, 4, 5, 6, 7, 8, 9, 10, 12};
    int obbiettivo, exit, mid, left, right;
    //per la ricerca è necessario dispore il vetto in ordine di valore (crescente, decrescente)
    sort(Vet.begin(), Vet.end(), less<int>());
    // se si vuole passare da crescente a decrescente invertire tutte le disugualianze

    for (auto &&i : Vet)
    {
        cout<<i<<" "; //per mostrare in che ordine è disposto il vettore
    }
    
    cout<<"\n inserisci il valore da cercare: ";
    cin>>obbiettivo;
       
    mid = Vet.size()/2;
    left = 0;
    right = Vet.size();

    while (exit != 0)
    {
        if(Vet[mid] < obbiettivo){
            left = mid;
            mid = (right-left)/2+left;

        } else if(Vet[mid] > obbiettivo){
            right = mid;
            mid = (right-left)/2+left;
        }else if (Vet[mid] == obbiettivo){
          exit = 0;  
        }
        if ((right-left)<2)
        {
            cout<<" numero non presente!";
            return 1;
        }
    }
    cout<<"posizione: "<< mid+1;

    return 0;
}