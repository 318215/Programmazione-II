/**
 * @file coda-bfs.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "albero-tipo.h"
#include "albero.h"
#include "coda-bfs.h"
#include <iostream>

using namespace std;

codaBFS newQueue() {

    codaBFS c;
    c.head = NULL;
    c.tail = NULL;

    return c;

}

/**  Restituisce vero se la coda è vuota, falso altrimenti. */

bool isEmpty(codaBFS c) {

    if(c.head == NULL) {

        return true;

    }

    return false;


}

/**  Restituisce il primo elemento della coda. */

node* first(codaBFS c) {

    return c.head->inf;

}

/**  Rimuove l'elemnto dalla coda secondo politica FIFO. */

node* dequeue(codaBFS& c) {

	node* ris=(c.head)->inf;
	c.head=(c.head)->pun;

    return ris;

}

/**  Accoda elemento alla coda tramite politica FIFO. */

codaBFS enqueue(codaBFS c, node* p) {

    elemBFS* l = new_elem(p);
    if(c.tail != NULL) {

        c.tail->pun = l;        

    }
    c.tail = l;

    if(c.head == NULL) {

        c.head = c.tail;

    }

    return c;

}

/**  Creo un nuovo elemento tipo elemBFS che sarà poi aggiunto alla coda. */

static elemBFS* new_elem(node* p) {

    elemBFS* l = new elemBFS ;
	l->inf=p;
	l->pun=NULL;

	return l;
    

}

/**  Funzione che ritorna la dimensione totale di un albero tramite funzione BFS. */

int dimensione(node* p) {

    int cont = 0;

    if(p != NULL) {

        codaBFS a = newQueue();
        a = enqueue(a,p);
        while(isEmpty(a) == false) {
            
            p = dequeue(a);
            cont++;
            tree p1 = get_firstChild(p);
            while(p1!=NULL){

                a = enqueue(a,p1);
             p1 = get_nextSibling(p1); 
            } 

        } 

        return cont;

    }else {

        return 0;

    }

}

/**  BFS ricorsiva che calcola la dimensione dell'albero. */

int dimRicorsiva(node* p) {  /* IN SOSPESO DIO CANE */

    int cont = 1;

    if(p == NULL) {

        return 0;

    }else {

        codaBFS a = newQueue();
        a = enqueue(a,p);
        while(isEmpty(a) == false) {
            
            p = dequeue(a);
            cont++;

            tree p1 = get_firstChild(p);
            while(p1!=NULL){

                a = enqueue(a,p1);
                return cont + dimRicorsiva(p1);
                p1 = get_nextSibling(p1); 
            } 

        } 


    }

    return cont+1;

}