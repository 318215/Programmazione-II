#include <iostream>

using namespace std;

int quadrato (int a) {

     return a*a;

}
int cubo (int a) {

    return a*a*a;

}

int main () {

   int (*puntafun[2]) (int) = { quadrato, cubo};
    int k,h;

    cout << "Scrivi uno per i quadrati, due per i cubi" << endl;
    cin >> h;

    cout << "fino a che numero" << endl;
    cin >> k;

    int ris = 0;

    for(int i = 0; i < k; i ++) {

        if(h == 1) {

            ris += (puntafun[0] (i+1));

        }else if( h == 2) {

            ris += (puntafun[1] (i+1));

        }else {
            cout << "Valore non previsto";
        }

    }

    cout << ris;


    return 0;
}