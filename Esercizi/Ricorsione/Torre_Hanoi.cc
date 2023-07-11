#include <iostream>

using namespace std;


void Torre_Hanoi (int n, char PioloS, char PioloD, char PioloA ) {

    if(n == 1) {

        cout << "Muovi il/i disco/chi dal piolo " << PioloS << " al piolo " << PioloD << endl;

    } else {
        cout << "Muoivi " << n-1 << " dischi dal piolo " << PioloS << " al piolo " << PioloD << endl;

        Torre_Hanoi(n-1,PioloS,PioloA,PioloD);

        cout << "Muovi " << n-1 << " dischi dal piolo " << PioloS << " al piolo " << PioloD << endl;

        Torre_Hanoi(n-1,PioloA,PioloD,PioloS);

    }


}

int main () {

    int dischi;
    char s,d,a; //sorgente destinazione appoggio

    cout << "inserisci il numero dei dischi" << endl;
    cin >> dischi;

    cout << "Qual è il tuo piolo sorgente?" << endl;
    cin >> s;

    cout << "Qual è il tuo piolo destinazione?" << endl;
    cin >> d;

    cout << "Qual è il tuo piolo d'appoggio?" << endl;
    cin >> a;

    Torre_Hanoi(dischi,s,d,a);

    return 0;
}