#include <iostream>

using namespace std;

int main () {

    int fib, somma;

    cout << "inserrisci il valore del quale calcolare la successione di fibonacci" << endl;
    cin >> fib;

    int dim = fib * fib;
    int arr[dim];

    for(int i = 0; i < dim; i ++) {

        arr[i] = 0;

    }

    for(int i = 0; i < dim; i+=2) {

        if(fib == 0 || fib == 1) {

            return 1;

        }else {

            arr[i] = fib - 1;
            arr[i+1] = fib - 2;
            fib--;

        }
    
    }

    for(int i = 0; i < dim; i ++) {

        somma += arr[i];

    }

    cout << "questo è il valore della tua successione" << endl;
    cout << somma;


    return 0;
}
