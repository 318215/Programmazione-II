#include <iostream>

using namespace std;

int Stampa_Decresc(int n) {

    if(n <= 0) {

        return 1;

    }else {

        cout << n << " ";
        return Stampa_Decresc(n-1);

    }

}

int main () {

    int n;

    cout << "insersici il numero del quale vuoi vedere stampati i precedenti" << endl;
    cin >> n;

    Stampa_Decresc(n);

    return 0;
}