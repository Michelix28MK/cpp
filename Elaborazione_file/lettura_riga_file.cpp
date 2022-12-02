#include <iostream>
#include <stdio.h>
    //doppio slesh per evitare errori come \n o \t
#define DIR "C:\\Users\\miche\\OneDrive\\Desktop\\Projects\\c++\\Elaborazione_file\\test.txt"

using std::cout, std::endl;

int main(){

    FILE * leggi; //creazione variabile di tipo file
    char riga[100];

    leggi = fopen(DIR,"r"); //apre file dal disco
    
    if (leggi == NULL) //controllo errori nel caricamento file
    {
        cout<<" file non caricato!";
        return 1;
    }

    fgets(riga, 100, leggi); //registra il numero di caratteri sulla variabie
    
    fclose(leggi);   //chiude file!

    cout<<riga<<endl; //funziona!

    return 0;
}