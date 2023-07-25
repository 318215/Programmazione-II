#include "tipo.h"
#include "liste.h"
#include <iostream>

using namespace std;

void pesca(lista &mazzo) {

    lista tmp;
    tipo_inf carta;

 
    cout << "Inserisci seme e valore!" << endl;
    cin >> carta.seme;
    cin >> carta.valore;
    
    tmp = new_elem(carta);


    mazzo = ord_insert_elem(mazzo, tmp);

}

void stampa(lista mazzo) {

    while(mazzo != NULL) {

        print(head(mazzo));
        mazzo = tail(mazzo);        

    }

}

int main () {

    int ncarte;
    lista m1 = new elem;
    m1->prev = NULL;
    m1->pun = NULL;
    lista m2 = new elem;
    m2->pun = NULL;
    m2->prev = NULL;

    cout << "Quante carte ci sono per giocatore?" << endl;
    cin >> ncarte;

    for(int i = 0; i < ncarte; i ++) {

        cout << "Inserisi la carta " << i+1 << " del giocatore 1" << endl;
        pesca(m1);

    }

    cout << "Mazzo giocatore 1" << endl;
    stampa(m1);

    for(int j = 0; j < ncarte; j++) {

        cout << "Inserisci la carta " << j+1 << " del giocatore 2" << endl;
        pesca(m2);
 
    }

    cout << "Mazzo giocatore 2" << endl;
    stampa(m2);



    return 0;
}