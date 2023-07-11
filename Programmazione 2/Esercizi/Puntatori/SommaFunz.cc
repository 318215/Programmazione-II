#include <iostream>

using namespace std;

int quadrato(int x) {

    return x*x;

}

int cubo (int x) {

    return x*x*x;

}

int somma( int (*punt)(int), int z ) {
    
    int ris = 0;

    while(z > 0) {

        ris += punt(z);

        z--;
    }

    return ris;

}

int main () {

    int (*punt[2]) (int) = {quadrato, cubo};

    int a,n;

    cout <<"0: Quadrato \n 1: Cubo" << endl;
    cin >> a;

    cout << "inserisci il numero di elementi di cui eseguire la somma" << endl;
    cin >> n;

    cout << somma(punt[a], n);

}