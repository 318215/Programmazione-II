#include <iostream>

using namespace std;

int fatt(int f) {

    if(f == 0) {

        return 1;

    }else if(f == 1) {

        return 1;

    }else{

        return f * fatt(f-1);

    }

}

int main () {

    int fat = 0;

    cout << "Inserisci il numero di cui vuoi calcolare il fattoriale" << endl;
    cin >> fat;

    cout << fatt(fat);


    return 0;
}