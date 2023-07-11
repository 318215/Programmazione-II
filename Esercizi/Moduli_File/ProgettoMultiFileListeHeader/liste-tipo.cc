#include "liste-tipo.h"
#include "liste.h"
#include <iostream>
#include <cstring>

using namespace std;

/* se dovessi cambiare il tipo di dato dovrei cambiare anche queste primitive che ne implementano il confronto, la stampa e la copia.*/

int compare(tipo_inf s1,tipo_inf s2) { 

    return strcmp(s1,s2);

}

void copy(tipo_inf s1, tipo_inf s2) {

    strcpy(s1,s2);

    return;

}

void print(tipo_inf s1) {

    cout << s1;

}