#include <iostream>
#include <fstream> // lettura e scrittura flusi di dati
#define dir "C:\\Users\\miche\\OneDrive\\Desktop\\Projects\\c++\\Elaborazione_file\\test2.txt"

using namespace std;

int main(){

    ofstream f(dir, ios::out); 
    /**
     * indica in che direzione va il flusso di dati
     * 
     * se la directory non dovesse esistere crea il file da sè
     * 
     * IMPORTANTE
     * il programma sovrascrive il contenuto del file (modalità ios::out)
     * usare ios::app per aggiungere del testo a uno già esistente
    */
    if (!f)
    {
        cout<<"errore file";
        return 1;
    }
    
    f<< "Forza italia"<<endl; //ciò che scrivi

    f.close(); //libera il file per l'accesso ad altri softeware

    cout<<"compleat!";

    return 0;
}