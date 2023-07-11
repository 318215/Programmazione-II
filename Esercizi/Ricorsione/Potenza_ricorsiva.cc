#include <iostream>

using namespace std;

double Elevamento(float n, int exp) {

    if(exp == 1) {

        return n;

    }else if(exp == 0) {

        return 1;

    }else if(n == 1) {

        return n;

    }

    if(exp > 0) {

        return n * Elevamento(n,exp-1);

    }

    return 1/n * Elevamento(n,exp-1);


}

int main () {

    float num;
    int e;

    cout << "inserisci il numero" << endl;
    cin >> num;
    cout << "inserisci l'esponente" << endl;
    cin >> e;

    Elevamento(num,e);

    cout << Elevamento(num,e);


    return 0;

}