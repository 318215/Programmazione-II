/**
 * @file albero.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;

#include "albero-tipo.h"
#include "albero.h"

/** Aggiunge un nuovo nodo al nostro albero. */

node* new_node(tipo_inf i){
	node* n=new node;
	copia(n->inf,i);
	n->nextSibling=n->firstChild=n->parent=NULL;
	return n;
}

/** Inserisce il nodo aggiunto come figlio del nodo passato come primo parametro. */

void insert_child(tree p, tree c){
	c->nextSibling=p->firstChild;
	c->parent=p;
	p->firstChild=c;
}

/** Inserisce il nodo aggiunto come fratello del nodo passato come primo parametro. */

void insert_sibling(node* n, tree t){
	t->nextSibling=n->nextSibling;
	t->parent=n->parent;
	n->nextSibling=t;
}

/** Ritorna il campo inf del nodo. */

tipo_inf get_info(node* n){
	return n->inf;
}

/** Ritorna il campo parent del nodo. */

node* get_parent(node* n){
	return n->parent;
}

/** Ritorna il campo firstChild del nodo. */

node* get_firstChild(node* n){
	return n->firstChild;
}

/** Ritorna il campo nextSibling del nodo. */

node* get_nextSibling(node* n){
	return n->nextSibling;
}

/** Stampa di ogni nodo dell'albero secondo la DFS Pre-Order. */

void serializza(node * t) {


    print(get_info(t));
	cout << ", ";	
	tree t1 = get_firstChild(t); 
	while(t1!=NULL){
        serializza(t1);
		t1 = get_nextSibling(t1); 
	}

}

/** Calcolo della profondità massima dell'albero attraverso la DFS Post-Order. */

int altezza(node * n) {

	if(get_firstChild(n)==NULL) {

		return 0;

	}

	int max=0, max_loc;

	tree n1 = get_firstChild(n);

	while(n1!=NULL){

		max_loc=altezza(n1);

		if(max_loc>max) {

			max=max_loc;

		}

		n1 = get_nextSibling(n1);
	}
	
	return max+1;

}

/**  Ricerca di un dato di tipo tipo_inf all'interno dei vari campi tipo_inf dei vari nodi attraverso DFS. */

bool search(tree t, tipo_inf v) {

	if(t == NULL) {

		return false;

	}

	if((compare(t->inf,v)) == 0) {

		return true;

	}

	tree t1 = get_firstChild(t); 
	bool a;

	while(t1!=NULL){

        a = search(t1,v);
		
		t1 = get_nextSibling(t1); 
		

	}

	return a;


}

/**  Ricerca di un cammino padre-figlio tra due nodi. */

bool esiste(tree t, node* t1) {

	if(t == NULL || t1 == NULL) {

		return false;

	}

	if(t->parent == NULL || t1->parent == t) {

		return true;

	}

	bool a;

	while(get_firstChild(t) != NULL) {

		a = esiste(get_firstChild(t),t1);
		return a;

	}


}

/**  Funzione che restituisce il numero di foglie dato un albero generico. */

int contaFoglie(node* t) {

	int foglie = 0;

	if(t == NULL) {

		return 0;

	}

	tree t1 = get_firstChild(t); 
	while(t1!=NULL){
		contaFoglie(t1);
	
		t1 = get_nextSibling(t1); 
		foglie++;

	}

	return foglie;

}
