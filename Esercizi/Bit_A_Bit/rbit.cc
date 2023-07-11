#include <iostream>

using namespace std;

int main () {

    int x, n;

    cout << "inserisci il numero del quale andremo a resettare i bit" << endl;
    cin >> x;
    cout << "inserisci la posizione del bit che vuoi venga resettato" << endl;
    cin >> n;

    n = ~(1<<n);  //questo ci permette dato ad esempio il numero 2, quindi il bit in posizione 2 aka 4
                  //di sottrarre 4 al numero da noi inserito.

    x = x & n; 
    cout << "il numero che avevi inserito è divnetato così: " << x;


    return 0;
}