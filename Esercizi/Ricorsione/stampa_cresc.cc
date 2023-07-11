#include <iostream>

using namespace std;

int Stampa_Cresc(int k,int n) {

    if(k == n) {

        cout << n << " ";
        return n;

    }else {

        cout << k << " ";
        return Stampa_Cresc(k+1,n);

    }

    

}

int main () {

    int n;

    cout << "Inserisci il numero del quale vuoi vedere stampati i precedenti" << endl;
    cin >> n;

    Stampa_Cresc(0,n);

    return 0;
}