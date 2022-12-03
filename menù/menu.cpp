#include <iostream>

using namespace std;

int main (){
    char select;

    cout<< "premi:\n (a) gioca \n (b) guarda \n (c) bevi \n \n Selezione: ";
    cin>>select;

    switch (select)
    {
    case 'a'/* constant-expression */:
        cout<<"\n do a";
        break;
    case 'b'/* constant-expression */:
        cout<<"\n do b";
        break;
    case 'c'/* constant-expression */:
        cout<<"\n do c";
        break;
    default:
        cout<<"opzione inesistente!";
        break;
    }

    return 0;
}