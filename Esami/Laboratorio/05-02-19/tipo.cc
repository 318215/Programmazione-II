#include <iostream>
#include "tipo.h"

using namespace std;

void print(tipo_inf c) {

    cout << c.seme;
    cout << c.valore << endl;

}

void copy(tipo_inf &c, tipo_inf t) {

    c.seme = t.seme;
    c.valore = t.valore;

}

int compare(tipo_inf c, tipo_inf t) {

    if(c.seme == t.seme && c.valore == t.valore) {

        return -1;

    }else if(c.seme == t.seme && c.valore > t.valore) {

        return -1;

    }else if(c.seme != t.seme){

        return -1;

    }else {

        return 0;

    }

}