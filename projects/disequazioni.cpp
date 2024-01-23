#include <iostream> //standard
#include <math.h>   //potenze e calcoli

using namespace std;

int parametro[2], incognita[1], delta;
void rileva_parametri()
{
    cout << "\n\n Inserisci a: ";
    cin >> parametro[0];
    cout << "\n Inserisci b: ";
    cin >> parametro[1];
    cout << "\n Inserisci c: ";
    cin >> parametro[2];

    cout << endl
         << "f(x) = " << parametro[0] << " x^2 + (" << parametro[1] << ")x + (" << parametro[2] << ")";
}
void calcolo_delta()
{
    delta = pow(parametro[1], 2) - (4 * parametro[0] * parametro[2]);
}
void calcolo_soluzione()
{
    if (delta == 0)
    {
        incognita[0] = (-parametro[1]) / (2 * parametro[0]);
    }
    else
    {
        incognita[0] = (-parametro[1] + sqrt(delta)) / (2 * parametro[0]);
        incognita[1] = (-parametro[1] - sqrt(delta)) / (2 * parametro[0]);
    }
}
void disponi_risultato()
{
    if (delta == 0)
    {
        cout << "X >= " << incognita[0];
    }
    else if (delta < 0)
    {
        if (parametro[0] > 0)
        {
            cout << "OGNI X";
        }
        else
        {
            cout << "NESSUN X";
        }
    }
    else
    {
        if (incognita[0] > 0)
        {
            if (incognita[0] < incognita[1])
            {
                cout << " X <= " << incognita[0] << " e  X >= " << incognita[1];
            }
            else
            {
                cout << " X <= " << incognita[1] << " e  X >= " << incognita[0];
            }
        }
        else
        {
            if (incognita[0] < incognita[1])
            {
                cout << incognita[0] << " <= X <= " << incognita[1];
            }
            else
            {
                cout << incognita[1] << " <= X <= " << incognita[0];
            }
        }
    }
}

int main()
{
    cout << "Data una funzione di 2 grado --> ax^2 + bx + c";
    rileva_parametri();
    calcolo_delta();
    cout << "\n\n Calcoliamo il delta --> b^2-4*(a)*(c) = " << parametro[1] << "^2 -4*(" << parametro[0] << ")*(" << parametro[2] << ") = " << delta;
    calcolo_soluzione();
    if (delta == 0)
    {
        cout << "\n\nEssendo che delta = 0 allora esiste una sola soluzione per l'equazione associata: \n\n X = -b/2a = " << (-parametro[1]) << "/" << (2 * parametro[0]) << " = " << incognita[0];
    }
    else if (delta < 0)
    {
        cout << "\n\nEssendo che delta < 0 allora non esiste X per cui f(x) = 0";
    }
    else
    {
        cout << "\n\nEssendo che delta > 0 allora esistono due soluzioni per l'equazione associata: \n\n X1,X2 = -b + delta^(1/2) / 2a, -b - delta^(1/2) /2a => \n\n"
             << (-parametro[1]) << " + " << sqrt(delta) << " / " << (2 * parametro[0]) << " = " << incognita[0] << "\n\n"
             << (-parametro[1]) << " - " << sqrt(delta) << " / " << (2 * parametro[0]) << " = " << incognita[1];
    }
    cout << "\n\nOttenuto il risultato dell'equazione associata possiamo definire che f(x) >= 0 per ";
    disponi_risultato();
}