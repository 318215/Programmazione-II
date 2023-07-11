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

#include <iostream>
#include "grafo.h"
#include "grafo-tipo.h"
#include "coda-bfs.h"


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

int first(codaBFS c) {

    return c.head->inf;

}

/**  Rimuove l'elemnto dalla coda secondo politica FIFO. */

int dequeue(codaBFS& c) {

	int ris=(c.head)->inf;
	c.head=(c.head)->pun;

    return ris;

}

/**  Accoda elemento alla coda tramite politica FIFO. */

codaBFS enqueue(codaBFS c, int p) {

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

static elemBFS* new_elem(int p) {

    elemBFS* l = new elemBFS ;
	l->inf=p;
	l->pun=NULL;

	return l;
    

}





 
