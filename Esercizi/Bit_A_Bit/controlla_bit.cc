#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cmath>

using namespace std;

const int dim = 10;

int main () {

    int v[dim],j,maschera,posizione;

    srand(time(NULL));

    for(int i = 0; i < dim; i ++) {

        j = rand()%100;
        v[i] = j;

    }

    for(int i = 0; i < dim; i ++) {

        cout << v[i];
        cout << " ";

    }

    cout << endl;


    cout << "Inserisci la posizione del bit da controllare e la maschera" << endl;

    cin >> posizione;
    cin >> maschera;

    // maschera = pow(2,maschera);

    maschera = 1 << maschera;

    if(posizione > dim) {

        cout << "non è possibile utilizzare una dimensione maggiore di 10" << endl;
        return 1;

    }else if(posizione < 0) {

        cout << "non è possibile utilizzare una dimensione minore di 10" << endl;

    }
    
    if((v[posizione] & maschera) != 0 ) {

        cout << "Bit settato" << endl;

    }else {

        cout << "Bit non settato" << endl;

    }


    return 0;
}