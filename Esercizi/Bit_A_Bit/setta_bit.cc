#include <iostream>

using namespace std;

int main () {

    int x, n;

    cout << "Inserisci una maschera" << endl;
    cin >> n;

    if(n <= 0) {

        cout << "Errore, la maschera di bit da assegnare al nostro numero non può essere minore di 0" << endl;

    }

    cout << "inserisci il numero a cui vuoi assegnare quei bit" << endl;
    cin >> x;

    x |= n;

    cout << x << endl;

    return 0;
}