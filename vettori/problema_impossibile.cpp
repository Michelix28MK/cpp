#include <iostream>
#include <math.h>
#define lim 10000 //range di ricerca

// algoritmo utilizzato per trovare il risultato di a^3 + b^3 = c^3
//spoiler (non esiste)

using namespace std;

int main(){
    double test;
    bool ris = false;
    for (float i = 1; i <= lim; i++ ){
        for (int j = 1; j <= lim; j++)
        {
            test = pow(i, 3) + pow( j, 3);
            //cout<<endl<<test<<endl;
            test = pow( test, 1/3.);
            //cout<<test<<endl;
            if (test == (int)test && i != j)
            {
                cout<<endl<<i<<"^3 + "<<j<<"^3 = "<<test<<"^3"<<endl;
                ris= true;
            }
        }
        cout<<"Elaborazione: "<<(i*100/lim)<<"%"<<" eseguito \n"; 
    }
    if (ris == false)
    {
        cout<<"numbers not found";
    }
    return 0;
}