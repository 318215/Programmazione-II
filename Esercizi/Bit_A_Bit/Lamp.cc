#include <iostream>

using namespace std;

void ripara(int &lamp, int pos) {

    if(pos < 0 || pos > 7 ) {

        cout << "ERRORE NELL'INSERIMENTO DELLA POSIZIONE" << endl;

        return;

    }

    pos = 1<<pos;
    lamp = lamp ^ pos;

}

void guasta(int &lamp, int pos) {

    if(pos < 0 || pos > 7 ) {

        cout << "ERRORE NELL'INSERIMENTO DELLA POSIZIONE" << endl;

        return;

    }

    pos = ~(1<<pos);
    lamp = lamp | pos;

}

void StampaLamp(int lamp) {

    int appoggio;

    for(int i = 0; i < 8; i ++) {

        appoggio = 1<<i;

        if((lamp & appoggio ) != 0) {

            cout <<"1";

        }else {

            cout << "0";

        }
        

    }

    cout << endl;

}

void RisparmioEnergetico(int lamp) {

    int appoggio;

    for(int i = 0; i < 8; i = i+2) {

        appoggio += 1<<i;

    }

    if((lamp & appoggio ) != 0 ) {

        cout << "è possibile abilitare il risparmio energetico" << endl;

    }else {

        cout << "non è possibile abilitare il risparmio energetico" << endl;

    }

}

int main () {

    char scelta;
    int l = 255,n;

    void (*punt[2]) (int&,int) = {ripara, guasta};

    do {

        cout <<"R: Riparazione \n G: Guasto \n L: Stampa \n K: Risparmio Energetico \n T: Termina" << endl;
        cin >> scelta;

        switch (scelta) {

            case 'R': {

              cout << "inserisci la posizione del bit che dovrà ripararsi" << endl;
                cin >> n;
                punt[0](l, n);
                break;

            }

            case 'G': {

                cout << "Inserisci la posizone del bit che dovrà guastarsi" << endl;
                punt[1](l,n);
                break;

            }

            case 'L': {

                cout << "Ecco a te i lampioni funzionanti" << endl;

                StampaLamp(l);
                break;

            }

            case 'K': {

                cout << "Controlliamo assieme se è possibile abilitare il risparmio energetico!! " << endl;

                RisparmioEnergetico(l);

                return 0;
        
            }

            case 'T' : {

                cout << "Grazie per aver usato il programma, a presto!" << endl;
                break;

            }

            default: {

                cout << "Valore non previsto" << endl;

            }

        }

    }while(scelta != 4);

    return 0;
}