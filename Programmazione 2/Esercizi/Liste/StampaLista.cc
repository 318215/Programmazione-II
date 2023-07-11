#include <iostream>

using namespace std;

struct elem {

    int inf;
    elem * punt;  //ricorsivo

};

typedef elem * lista;
lista testa;

int head(lista l){
    
    return l->inf;
    
}

lista tail(lista l){
    
    return l->punt;
    
}

void stampalista(lista p){

     while (p != NULL) {

        cout << head(p) << " " ; // stampa valore in testa 
        p = tail(p); // spostamento sulla coda di p

    }

    cout << endl;

}

int main () {

    lista testa = new elem;

    testa->inf = 3;



    elem * p = new elem; // creo l'elemento 
    
    p->inf = 7;
    p->punt = NULL;
    testa->punt = p; //aggancio l'elemento 
    stampalista(testa);

    return 0;

}