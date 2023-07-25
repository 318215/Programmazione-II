#include <iostream>
#include <fstream>
#include "node.h"
#include "grafi.h"

using namespace std;

/** Funzionche che ci permette di stampare in Verbosity Mode il contenuno dei due file caricati 
 * rispettivamente su grafo e su vettore dinamico.
 *  
 * @param Grafo
 * @param ArrayDinamicoNodi
 * 
 *  */

void stampa(graph G, node* n) {

    adj_list tmp;
    int appoggio = 0;

    for (int i=0; i<get_dim(G); i++) {

        tmp=get_adjlist(G,i+1);

        while (tmp) {
            cout << n[i].cont << " ";
            appoggio = get_adjnode(tmp);
            appoggio --;
            if(n[i].tipo == 'U' && n[appoggio].tipo == 'U') {

                cout << " FOLLOW " << n[appoggio].cont << endl;

            }else if(n[i].tipo == 'U' && n[appoggio].tipo == 'T') {

                cout << " LIKE " << n[appoggio].cont << endl;

            }else if(n[i].tipo == 'T' && n[appoggio].tipo == 'U') {

                cout << " OWNERSHIP " << n[appoggio].cont << endl;

            }

	        tmp=get_nextadj(tmp);

        }


    cout << endl;

    }


}
/**
 * In questa funzione andiamo a contare il numero totale di like ricevuti per ogni tweet e nel main conteremo il massimo.
 * 
 * 
 * 
 * @param Grafo @param ArrayDinamicoNodi
 * 
 * @return ArrayDinamicoLike
 * 
 */
/*int* totalLike(graph G, node* n) {

    adj_list tmp,app;
    int appoggio = 0,nodo = 0,contaLike = 0;
    int* like = new int[get_dim(G)];

    for (int i=0; i<get_dim(G); i++) {

        if(n[i].tipo == 'U') {
            tmp=get_adjlist(G,i+1);

            while (tmp) {
                appoggio = get_adjnode(tmp);

                if(n[appoggio-1].tipo == 'T') {

                    contaLike++;
                    
                    app = get_adjlist(G,appoggio);

                    while(app) {

                        nodo = get_adjnode(app);

                        if(n[nodo-1].tipo == 'U') {

                            like[nodo] = contaLike;

                        }

                        app = get_nextadj(app);

                    }

                }
           

	            tmp=get_nextadj(tmp);

            }


        }else {

            like[i] = 0;

        }

    }

    return like;


}*/

/** ::main Nel main andremo a caricare da file il nostro grafo e il nostro array dinamico di nodi, dopodichè 
 * li passaremo alla funzione stampa per fare sì che vengano messi a schermo.
 * 
*/

int main () {


    ifstream f("graph.txt");

    if(!f) {

        cerr << "ERRORE DURANTE L'APERTURA DEL FILE IN LETTURA" << endl;

    }
    
    int dim = 0, s, d,w = 0;

    f >> dim;

    graph g = new_graph(dim);

    while(f.good()) {

        f >> s;
        f.ignore();
        f >> d;
        f.ignore();

        add_arc(g,s,d,w);

    }


    ifstream f2 ("node.txt");

    if(!f2) {

        cerr << "ERRORE DURANTE L'APERTURA DEL FILE IN LETTURA" << endl;

    }

    node* nodi = new node[get_dim(g)];
    int j = 0;

    while(f2.get() != EOF) {

        f2.getline(nodi[j].cont,81);
        f2 >> nodi[j].tipo;
        j++;

    }

    f2.close();


    stampa(g,nodi);

    /*int* l = totalLike(g,nodi);

    int max = 0,k;

    for(int i = 0; i < get_dim(g); i++) {
    
        max = l[i];   
        if(max < l[i]) {

            max = l[i];

        }else if(max == l[i]) {

            k = i;

        }

    }

    cout << max << " É uno tra gli utenti ad aver ricevuto più like!" << endl;
    if(l[k] == max) {

        cout << l[k] << " É uno tra gli utenti ad aver ricevuto più like!" << endl;

    }*/
    

    return 0;
}