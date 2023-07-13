/**
 * @file grafo.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

#include "coda-bfs.h"
#include "grafo.h"

using namespace std;


//* Crea una nuova lista di adiacenza con dimensione dim. */

graph new_graph(int n) {

    graph g;
    g.dim = n;
    g.nodes = new adj_list[g.dim];

    for(int i = 0; i < g.dim; i++) {

        g.nodes[i] = NULL;

    }

    return g;

}

/** Aggiunge un arco orientato da s verso d di peso w alla lista di adiacenza di s. */

void add_arc(graph& g,int s,int d,float w) {

    adj_node* t = new adj_node;
    t->node = d-1;
    t->weight = w;
    t->next = g.nodes[s-1];
    g.nodes[s-1] = t;

}

/** Aggiunge un arco non orientato tra i due vertici di peso w. */

void add_edge(graph &g,int s,int d,float w) {

    adj_node* t = new adj_node;

    add_arc(g,s,d,w);
    add_arc(g,d,s,w);


}

/** Funzione che ritorna il numero di vertici del nostro grafo. */

int get_dim(graph g) {

    return g.dim;

}

/** Funzione che ritorna una determinata lista di adiacenaza. */

adj_list get_adjlist(graph g,int s) {

    return g.nodes[s];

}

/** Funzione che restituisce un determinato vertice. */

int get_adjnode(adj_node* p) {

    return p->node+1;

}

/** Funzione che restituisce il puntatore alla prossima lista di adiacenza. */

adj_list get_nextadj(adj_list p) {

    return p->next;

}
/** Funzione che restituisce il peso di un determinato vertice. */

float get_adjweight(adj_node* l){

	return (l->weight);
    
}

