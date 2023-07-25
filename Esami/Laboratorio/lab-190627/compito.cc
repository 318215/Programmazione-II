#include <iostream>
#include <fstream>

using namespace std;

#include "tipo.h"
#include "liste.h"
#include "grafo.h"

/** Funzione che ci permette di caricare da file la nostra lista contenente i Punti Di Interesse. */

int carica(lista &pi) {

    int quanti = 0;

    ifstream f("PI.txt");

    if(!f) {

        cerr << "ERRORE DURANTE L'APERTURA DI UN FILE IN LETTURA" << endl;

    }  

    while(f.good()) {

        tipo_inf p;
        f >> p.id;
        f.ignore();
        f.getline(p.nome, 21);
        f >> p.tipo;
        f.ignore();

        lista h = new_elem(p);

        pi = ord_insert_elem(pi,h);

        quanti++;

    }
 
    return quanti;

}

/** Funzione che ci permette di ricercare all'interno della nostra lista ordinata un determinato punto di interesse mediante l'ID. */

tipo_inf searchID(lista pi, int ID) {

    while(tail(pi) != NULL) {

        if(head(pi).id > ID) {

            cout << "Non è presente il dato richiesto" << endl;
            tipo_inf x;
            x.id = 0;
            for(int i = 0; i < 21; i++) {

                x.nome[i] = ' ';

            }
            x.tipo = 'X';
            return x;

        }else if(head(pi).id == ID) {

            return head(pi);

        }else if(ID > head(pi).id) {

            pi = tail(pi);

        }

    }

}

/** Funzione che ci permette di caricare la "mappa" ovvero il nostro grafo da file. */

graph mappa(int n) {

    graph G = new_graph(n);

    ifstream f2("G.txt");

    if(!f2) {

        cerr << "ERRORE DURANTE L'APERTURA DI UN FILE IN LETTURA" << endl;

    }

    int s,d;

    while(!f2.eof()) {

        f2 >> s;
        f2 >> d;

        add_arc(G,s,d,0);

    }

    return G;

}

/** In questa funzione avviene la stampa della nostra mappa. */

void stampaMappa(graph G, lista pi) {

    adj_list tmp;

    for (int i=1; i<=get_dim(G); i++) {

        tipo_inf app = searchID(pi,i);
        cout << app.nome <<endl;
        tmp=get_adjlist(G,i);
        cout << i;
        while (tmp != NULL) {

	        cout << " --> " << get_adjnode(tmp);
	        tmp=get_nextadj(tmp);

        }


        cout << endl;

    }

}

/** Funzione che ci permette di visualizzare a schermo i punti raggiungibili da un determinato nodo che abbiano lo stesso tipo di punto di interesse. */

void trip(graph G, int node, lista pi) {

    adj_list tmp;

    tipo_inf app = searchID(pi,node);
    tmp=get_adjlist(G,node);


    while (tmp != NULL) {

        if(get_nextadj(tmp) != NULL) {

            tipo_inf app2 = searchID(pi,tmp->next->node);
            if(app.tipo == app2.tipo) {
                
                cout << tmp->node << " ----> ";
                app = app2;
                tmp = get_nextadj(tmp);

            }else {

                tmp = get_nextadj(tmp);

            }

        }else {

            cout << "il nodo non ha archi uscenti" << endl;
            return;

        }

    }

    cout << "il nodo non ha archi uscenti" << endl;
    return;


}

/** ::main Creiamo la lista la riempiamo da file, creiamo il grafo e lo riempiamo da file, aggiungiamo la funzione di stampa e di ricerca di un punto di interesse. */

int main () {

    lista l;
    int dim = 0,id,nodo;
    char scelta;
    cout << "Abbiamo caricato da file " << carica(l) << " punti di interesse" << endl;
    dim = carica(l);
    
    do {
        cout << "Inserisci l'id da ricercare all'interno della lista: " << endl;
        cin >> id;

        tipo_inf ris = searchID(l,id);
    
        if(id > dim) {

            cout << "L'identificativo non è stato trvoato" << endl;

        }else {

            print(ris);

        }

        cout << "Inserire 'S' per fermare la ricerca, un qualunque altro carattere per continuare" << endl;
        cin >> scelta;

    }while(scelta != 'S');

    graph g = mappa(dim);

    stampaMappa(g,l);

    cout << "Inserisci il nodo del quale calcolerò tutti i cammini disponibili attraverso solamente nodi dello stesso tipo! " << endl;
    cin >> nodo;

    return 0;
    
}