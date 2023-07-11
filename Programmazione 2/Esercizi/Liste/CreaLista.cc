#include <iostream>

using namespace std;

struct elem {

    int inf;
    elem * punt;

};

typedef elem * lista;

int head(lista l) {
    
    return l->inf;
    
}

lista tail (lista l) {

    return l->punt;

}

void stampalista(lista p){ 

    while (p != NULL) {

        cout << head(p) << " " ; // stampa valore in testa 
        p = tail(p); // spostamento sulla coda di p
    
    }
    
    cout << endl ;

}

lista insert_elem(lista l, elem* e) {

     e->punt=l;

    return e;

}



lista delete_elem(lista l, elem* e) {

    if (l==e) {

        l=tail(l);

    }
        
    else{

        lista l1=l;

        while (tail(l1)!=e) {

            l1=tail(l1);

        }

        l1->punt=tail(e);

    }

    delete e;

    return l; 
    
}

void EliminaLista(lista &p) {

    while (p != NULL) {

        p=delete_elem(p,p);

    }
    
}

void CreaLista(int n) {

    lista testa = new elem;
    cin >> testa->inf;

    for(int i = 0; i < n-1; i ++) {

        lista r = new elem;
        cin >> r->inf;
        r->punt = NULL;
        testa = insert_elem(testa,r);      

    }

    stampalista(testa);

    EliminaLista(testa);

    stampalista(testa);

}

int main () {

    int dim;

    cout << "inserisci il numero di elementi che desideri concatenare in una lista" << endl;
    cin >> dim;

    CreaLista(dim);
    



    return 0;
}