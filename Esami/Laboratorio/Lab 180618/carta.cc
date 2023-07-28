#include <iostream>

#include "carta.h"

using namespace std;

/** Funzione che permette di controllare se il campo informativo di due nodi dell'albero sono uguali o meno. */

int compare(tipo_inf n1, tipo_inf n2) {

    if(n1.Nominativo == n2.Nominativo && n1.punti == n2.punti) {

        return 0;

    }

    return 1;

}

/** Stampa del campo informativo di un nodo di un albero binario. */

void print(tipo_inf n1) {

    cout << n1.Nominativo << endl;
    cout << n1.punti << " punti" << endl;

}

/** Copia da un nodo all'altro del suo campo informativo. */

void copy(tipo_inf &n1, tipo_inf n2) {

    strcpy(n1.Nominativo,n2.Nominativo);
    n1.punti = n2.punti;

}