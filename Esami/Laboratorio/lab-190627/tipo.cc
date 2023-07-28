#include <iostream>
#include "tipo.h"
#include <cstring>

using namespace std;

/** Funzione che copia nel primo struct di tipo tipo_inf tutti i campi del secondo struct. */

void copy(tipo_inf &c, tipo_inf t) {

    c.id = t.id;
    c.tipo = t.tipo;
    strcpy(c.nome,t.nome);

    return;

}

/** Funzione che stampa tutti i campi dello struct tipo_inf. */

void print(tipo_inf c) {

    cout << c.id << endl;
    cout << c.nome << endl;
    cout << c.tipo << endl;

    return;

}

/** Funzione ausiliaria a ord_insert_elem che permette il corretto inserimento in modo ordinato. */

int compare(tipo_inf c, tipo_inf t) {

    if(c.id > t.id) {

        return 1;

    }else if(c.id == t.id){

        return 0;

    }else if(c.id < t.id) {

        return -1;

    }

}