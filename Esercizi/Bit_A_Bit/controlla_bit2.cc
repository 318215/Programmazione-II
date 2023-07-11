#include <iostream>
#include <cmath>

using namespace std;

int main () {

    int n, maschera;

    cout << "Insersici il numero e la maschera" << endl;

    cin >> n >> maschera;

    maschera = pow(2,maschera);

    if((n & maschera) != 0) {

        cout << "Bit settato" << endl;

    }else  {

        cout << "Bit non settato" << endl;

    }


    return 0;
}