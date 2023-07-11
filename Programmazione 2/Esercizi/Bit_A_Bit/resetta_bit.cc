#include <iostream>
#include <cmath>


using namespace std;

int main () {

    int x,n;

    cout << "Inserisci il numero" << endl;
    cin >> x;

    cout << "Inserisci posizione del bit da resettare" << endl;
    cin >> n;

    n = pow(2,n);
    x ^= n;        

    cout << x;

    return 0;
}

