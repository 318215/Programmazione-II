#include <iostream>
#include "carta.h"
#include "bst.h"

using namespace std;


void sommaIntervallo(bst T, bst inf, bst sup , int&s) {

    if(get_left(T) != NULL) {

        if(T->inf.punti >= inf->inf.punti && T->inf.punti <= sup->inf.punti) {

            s+=T->inf.punti;

        }
        sommaIntervallo(get_left(T),inf,sup,s);

    }

    if(get_right(T) != NULL) {

        if(T->inf.punti >= inf->inf.punti && T->inf.punti <= sup->inf.punti) {

            s+=T->inf.punti;

        }
        sommaIntervallo(get_right(T),inf,sup,s);

    }
    

}

/** Funzione che mi permette di ritornare la somma di tutti i punti generati dalle carte fedeltà comprese in un determinato intervallo. */

int totalePunti(bst Tree,tipo_key inf, tipo_key sup) {

    int somma = 0;

    bst T1 = bst_search(Tree,inf);

    bst T2 = bst_search(Tree,sup);

    if(T2->key < T1->key) {

        return somma;

    }else if(T2->key == T1->key) {

        somma = T2->inf.punti;
        return somma;

    }

    sommaIntervallo(Tree,T1,T2,somma);

    return somma;

} 


/** Funzione che ci permette di aggiungere dei punti in caso qualche persona abbia fatto un acquisto con la propria carta fedeltà. */

void aggiorna(bst Tree, tipo_key seriale, int punti) {

    Tree = bst_search(Tree, seriale);

    Tree->inf.punti += punti;

}

/** ::main Comprende la gestione delle stampe e dell'inserimento di n carte fedeltà che verranno appositamente gestite dalle varie funzioni. */

int main () {

    int ncarte,punti;
    char scelta;
    tipo_key seriale,seriale_Bis;

    cout << "Quante carte vuoi inserire??" << endl;
    cin >> ncarte;

    bst Tree;

    for(int i = 0; i < ncarte; i ++) {

        tipo_inf cartaF;
        cout << "Inserisci il seriale della carta " << i+1 << " :" << endl;
        cin >> seriale;
        cout << "Inserisci l'intestatario/a: " << endl;
        cin >> cartaF.Nominativo;
        cout << "Inserisci i punti da caricare su questa carta: " << endl;
        cin >> cartaF.punti;

        bst T = bst_newNode(seriale,cartaF);
        bst_insert(Tree,T);

    }

    stampaCrescente(Tree);
    cout << endl;
    
    do {

        cout << "Inserisci i dati per un acquisto: Seriale, Punti" << endl;
        cin >> seriale;
        cin >> punti;

        aggiorna(Tree,seriale,punti);

        cout << "Ora i punti aggiornati sono così: " << endl;
        stampaCrescente(Tree);

        cout << "Vuoi smettere? Per smettere inserisci il carattere 'S'" << endl;
        cin >> scelta;

    }while(scelta != 'S');

    cout << "Inserisci due seriali che andiamo a fare una somma dei punti!" << endl;
    cin >> seriale;
    cin >> seriale_Bis;

    cout << totalePunti(Tree,seriale,seriale_Bis);


    

    return 0;

}