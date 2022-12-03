#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define dir "C:\\Users\\miche\\OneDrive\\Desktop\\Projects\\c++\\Elaborazione_file\\test.txt"
using std::cout, std::endl;

int main(){

    FILE * testo;

    char cTesto [1000];

    testo = fopen(dir, "r");
    if (testo == NULL){
        cout<<"errore caricamento!";
        return 1;
    }
    while (!feof(testo)) //fino al termine del file
    {
        fgets(cTesto, 1000, testo);
        cout<<cTesto<<endl;
    }

    fclose(testo);
    
    return 0;
}