#include <iostream>

using namespace std;

int fibonacci(int num) {

    if(num == 0 || num == 1) {

        return num;

    }

    return fibonacci(num - 1) + fibonacci(num - 2);

}

int main () {

    int n;

    cout << "inserisci il numero del quale calcolare la serie di fibonacci" << endl;
    cin >> n;

    cout << fibonacci(n);

    return 0;

}