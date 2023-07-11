#include <iostream>

using namespace std;

int main () {

    int x, n;

    cout << "insersici il numero da controllare" << endl;
    cin >> x;

    cout << "Inserisci la posizione del bit da controllare" << endl;
    cin >>n;

    n = 1<<n;

    if((x & n) != 0) {

        cout << "bit settato" << endl;

    }else {
        
        cout << "bit non settato" << endl;
        
    }



    return 0;
}