#include <iostream>

using namespace std;

void funzione ( int *a, int *b, int *c){ //indicazione di passaggio indirizzo

    cout<<"valore di a in funzione: "<<a<<endl; //output dell'indirizzo per via della passaggio in funzione
    cout<<"valore di *a: "<<*a<<endl; // utilizzare (*) per usare il valore presente all'indirizzo.

    *c= *a + *b; //elaborazione
}

int main(){

    int a=2, b=1, c;

    cout<<"indirrizzo della variabile a: "<<&a<<endl; //output dell'indirizzo della variabile con l'apposizione di (&)

    funzione(&a, &b, &c); //passaggio indirizzo

    cout << c; 

    return 0;
}