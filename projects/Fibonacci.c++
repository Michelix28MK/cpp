#include <iostream>
#include <string>
#include <math.h>

using std::cout, std::cin, std::endl;

int righe_sequenza , sequenza_fibonacci [1000] [1000] ={0};

int main(){
    //dischiarazione numero di righe
    do
    {
        cout << endl << "inserisci il numero di righe che desideri visualizzare della sequenza di Fibonacci: ";
        cin >> righe_sequenza;

        if (righe_sequenza<2)
        {
            cout << "inserisci un valore maggiore di 2!" << endl;
        }
    }while (righe_sequenza < 3 || righe_sequenza > 1000);
    // impostazione margini della sequenza
    for (int x = 1; x < righe_sequenza; x++)
    {
        sequenza_fibonacci[x][0] = 1;
        sequenza_fibonacci[x][x] = 1;
    }
    // riempimento sequenza
    for (int i = 2; i < righe_sequenza; i++)
    {  
        for (int j = 1; j < i; j++)
        {
            sequenza_fibonacci[i] [j] = sequenza_fibonacci[i-1] [j-1] + sequenza_fibonacci[i-1] [j];
        }
    }
    
    cout<<"ecco la sequenda di Fibonacci fino alla "<< righe_sequenza <<" riga:"<<endl;
    // esposizione sequenza
    for (int i = 0; i < righe_sequenza; i++)
    {   //modulo per la forma triangolare
        for(int space = 1; space <= righe_sequenza-i; space++)
        {
            cout <<"  ";
        }
            
        for (int j = 0; j <= i; j++)
        {               
            cout<<sequenza_fibonacci[i][j]<<"   "; //gli spazzi alla fine servono per correggere la forma della piramide 
        }
        cout<<endl;
    }
    
    system("pause");
    return 0;
}