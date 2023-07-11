#include <iostream>

using namespace std;

struct elem {

    int inf;

    elem * punt; //ricorsivo

};

typedef elem * lista;

lista testa;

int Head (lista l) { 

    return l->inf;  
    
}    

lista Tail(lista l) {

    return l->punt;

}

void stampaLista(lista l) {

    while(l != NULL) {

        cout << Head(l);
        l = Tail(l);

    }

}

lista insert_elem(lista l, elem* e) {

    e->punt=l;

    return e; 
        
}

lista delete_elem(lista l, elem* e) {

    if (l==e) { //controllo se e sia la testa della lista

            l=Tail(l);

        }else{

            lista l1=l;
            while (Tail(l1)!=e){ //localizzo l'elemento che punta ad e

                l1=Tail(l1);

            }
        l1->punt=Tail(e); //aggiorno l'elemento che punta ad e

        }
    delete e;
    return l;

}

int main () {

    testa = new elem;
    testa->inf = 2;
    testa->punt = NULL;

    int n;

    cout << "inserisci il numero di elementi della tua lista" << endl;
    cin >> n;

    for(int i = 0; i < n; i ++) {

        lista el = new elem;
        cin >> el->inf;
        el->punt = NULL;
        testa = insert_elem(testa,el);

    }



    stampaLista(testa);

    


}