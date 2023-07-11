#include <iostream>

using namespace std;

int main () {

    int x, n;

    cout << "insersici il numero del quale setteremo i bit"  << endl;
    cin >> x;
    cout << "insersici la posizione dei bit da settare" << endl;
    cin >> n;

    n = 1<<n;

    x = x | n;

    cout << "il numero da te inserito è diventato: " << x << endl;

    return 0;
}