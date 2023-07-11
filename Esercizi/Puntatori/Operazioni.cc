#include <iostream>

using namespace std;

double somma(double a, double b) {

    return a+b;

}

double sottrazione(double a, double b) {

    return a-b;

}

double moltiplicazione(double a, double b) {

    return a*b;

}

double divisione(double a, double b) {

    return a/b;

}

int main () {

    double (*punt[4]) (double, double) = {somma, sottrazione, moltiplicazione, divisione};

    int x,y;
    int i; //Scelta

    cout << "che operazione vuoi effettuare?" << endl;
    cout << "0: Somma \n 1: Sottrazione \n 2: Moltiplicazione \n 3: Divisione" << endl;
    cin >> i;

    cout << "inserisci ora i valori dei due membri che verranno confrontati." << endl;
    cin >> x;
    cin >> y;

    cout << punt[i](x,y);

    return 0;
}