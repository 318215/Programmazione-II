/**
 * @file main.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
#include <cstring>

#include "grafo.h"
#include "coda-bfs.h"
#include "grafo-tipo.h"

using namespace std;

/** Funzione che mi compone il grafo a partire da un file di testo. */

graph g_build(istream &g,bool a,bool b) {  /** @param graph1.w @return grafo aggiornato. */

    int dim,n1,n2,w;
    g >> dim;

    graph H = new_graph(dim);

    while(g.get() != EOF) {

        g >> n1;
        g >> n2;
        g >> w;

        if(a == true && b == true) {

            add_arc(H,n1,n2,w);

        }else if(a == false && b == true) {

            add_edge(H,n1,n2,w);

        }else if(a == true && b == false) {

            add_arc(H,n1,n2,0);

        }else if(a == false && b == false) {

            add_edge(H,n1,n2,0);

        }

    }

    return H;

}

/** Funzione che mi restituisce vero se il grafo è connesso altrimenti restituisce false. */

bool connected(graph g, int v){
	bool* raggiunto = new bool[get_dim(g)];
	int* padre = new int[get_dim(g)];
	int i;

	for(int i=0; i<get_dim(g); i++)
		raggiunto[i]= false;
	for(int i=0; i<get_dim(g); i++)
			padre[i]= -1;
	codaBFS C=newQueue();
	raggiunto[v-1]=true;
	C=enqueue(C,v);
	while(!isEmpty(C)){
		int w=dequeue(C);
		for(adj_node* n=get_adjlist(g,w);n!=NULL;n=get_nextadj(n)){
			i = get_adjnode(n);
			if(!raggiunto[i-1]){
				raggiunto[i-1]=true;
				padre[i-1]=w-1;
				C=enqueue(C,i);}
		}
	}
	for(int i=0;i<get_dim(g);i++)
		if(!raggiunto[i])
			return false;
	cout<<"Spanning tree del nodo "<<v<<endl;
	for(int i=0;i<get_dim(g);i++)
		if (padre[i]!=-1)
			cout<<"il padre del nodo "<<i+1<<" e' il nodo "<<padre[i]+1<<endl;
	return true;
}

/** Funzione che controlla se il grafo è bipartito e ritorna "true" nel caso. */

bool Bipartito(graph G,int v) {

    adj_list l = new adj_node;

    if(v % 2 == 0) {

        l = get_adjlist(G,v);
        while(l) {

            if(l->node % 2 != 0) {

                return false;

            }

            l=l->next;

        }
        
        return true;

    }else {

        l = get_adjlist(G,v);
        while(l) {

            if(l->node % 2 == 0) {

                return false;

            }

            l=l->next;

        }

        return true;

    }

}

int main (int argc, char *argv[]) {

    bool d,w;
    d = static_cast<bool>(argv[1]);
    w = static_cast<bool>(argv[2]);

    graph G;

    if(argc < 3 || argc > 3) {

        cout << "Errore hai inserio un numero scorretto di argomenti. " << endl;
        return 0;

    }

    ifstream f("graph1.w");

    if(!f) {

        cerr << "Errore durante l'apertura del file il lettura! " << endl;
        return 0;

    }

    G = g_build(f,d,w);

    adj_list tmp;

    for (int i=1; i<=get_dim(G); i++) {

        tmp=get_adjlist(G,i);
        cout << i;
        
        while (tmp) {

	        cout << " --> " << get_adjnode(tmp);
	        tmp=get_nextadj(tmp);

        }


    cout << endl;

    }

    connected(G,1);
    if(Bipartito(G,1) == true) {

        cout << "Il grafo è bipartito" << endl;

    }else {

        cout << "Il grafo non è bipartito" << endl;

    }

    return 0;

}