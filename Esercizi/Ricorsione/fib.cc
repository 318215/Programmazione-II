#include <iostream>

using namespace std;

int fib(int n) {

    if(n == 1 || n == 0) {

        return n;

    }else {

        return fib(n-1) + fib(n-2);

    }


    
}

int main () {

    int fibonello = 0;

    cout << "inserisci il numero di cui verrà calcolata la successione di fibonacci" << endl;
    cin >> fibonello;

    cout << fib(fibonello);


    return 0;
}