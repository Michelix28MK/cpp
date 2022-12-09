#include <iostream>
#include <vector>


using namespace std;


int main(){
    
    vector<int> Vet{ 3, 15 , 78 , 14 ,11};
    int limite = 0, Us, temp, n = Vet.size();
    bool scambio = false; 

    cout<<"Vettore iniziale: ";
    for (auto &&j : Vet)
    {
        cout << j << " ";
    }
    do{   
        scambio = false;

        for (int i = n-1; i > limite ; i--)
        {   
            if (Vet[i] < Vet[i-1])
            {   
                cout<< "\n Scambio "<< Vet[i]<<" e "<<Vet[i-1]<<endl;
                temp = Vet[i];
                Vet[i] = Vet[i-1];
                Vet[i-1] = temp;
                Us = i;
                scambio = true;
            }
        } 
        limite = Us; 

    } while (scambio != false);

    cout<<"\n Vettore finale: ";
    for (auto &&i : Vet)
    {
        cout << i<< " ";
    }

    return 0;
}