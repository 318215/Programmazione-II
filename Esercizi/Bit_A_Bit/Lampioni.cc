#include <iostream>
#include <cmath>

using namespace std;

const int dim = 3;

void AggiungiLampione(int &l, int b) {

     b = 1<<b;

    if((l & b) != 0 ) {

        l ^= b;

    }else {

        l |= b;

    }

}

void StampaLampioni(int &l, int b) {

    for(int i = 0; i < 8; i++) { // prima partiva da 1 a 9

        b = 1 << i;

        if((l & b) != 0) {

            cout << "1";

        }else {

            cout << "0";

        }

    }

    cout << endl;

}

void RisparmioEnergetico(int &l, int b) {

    int contatore = 0;

    for (int i = 0; i < 8; i+=2) {

        b = 1 << i;

        if((l & b) != 0) {

            contatore ++;

        }

    }

    if(contatore == 4) { 

        cout << "Lampioni in posizione pari accesi" << endl;

    } else {
        
        cout << "Semafori in posizione pari non accesi, ora proviamo con quelli dispari" << endl;

    }
    
    contatore = 0;

    for(int i = 1; i < 8; i+=2) {

        b = 1 << i;

        if((l & b) != 0) {

            contatore ++;

        }

    }

    if(contatore == 4) {

        cout << "Lampioni in posizione dispari accesi" << endl;

    }else {

        cout << "Non tutti i lampioni in posizione dispari sono accesi" << endl;

    }

}


int main () {

    int l = 255;

    void (*p[dim]) (int &, int) = { AggiungiLampione, StampaLampioni, RisparmioEnergetico};

    int scelta,bit = 0,d;

    while(true) {

        cout << "Menu:" << endl;
        cout << "1 per aggiornare lo stato di un lampione" << endl << "2 per stampare i lampioni attivi" << endl << "3 per verificare il risparmio energetico" << endl << "4 per uscire dal programma" << endl;

        cin >> scelta;

        switch(scelta) {

            case 1: {

                cout << "Inserisci la posizione del lampione da attivare" << endl;
                cin >> bit;

                if(bit > 8 && bit < 1) {

                    cout << "Errore, sono prensenti 8 lampioni, non di più non di meno!" << endl;
                    break;

                }

                d = scelta - 1;

                (p[d] (l,bit));

                break;

            }

            case 2: {

                d = scelta - 1;

                (p[d] (l,bit));

                break;

            }

            case 3: {

                d = scelta - 1;

                (p[d] (l,bit));

                break;

            }

            case 4: {

                cout << "Grazie per aver usato il mio programma!" << endl;
                return 0;

            }

            default: {

                cout << "Valore non previsto!" << endl;

            }


        }


    }


    return 0;
}

