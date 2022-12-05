#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    
    vector<int> Vet{ 3, 15 , 78 , 14 ,11};

    cout<<"\n\nBefore sorting vector : ";
	for(auto i=Vet.begin(); i<Vet.end(); i++)
	{
		cout<<" "<<*i;
	}

    sort(Vet.begin(), Vet.end(), greater<int>()); //ordina i vettori dal più grande al più piccolo
    
    cout<<"\n\nAfter sorting vector greater: ";
	for(auto i=Vet.begin(); i<Vet.end(); i++)
	{
		cout<<" "<<*i;
	}

    sort(Vet.begin(), Vet.end(), less<int>()); //ordina i vettori dal più piccolo al più grande

    cout<<"\n\nAfter sorting vector smaller: ";
	for(auto i=Vet.begin(); i<Vet.end(); i++)
	{
		cout<<" "<<*i;
	}
    return 0;
}