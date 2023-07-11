#include "liste-tipo.h"
#include "liste.h"
#include <iostream>
#include <cstring>

using namespace std;

tipo_inf head(lista p){
	return p->inf;
}

elem* search(lista l, tipo_inf v){

	if(l == NULL) {
		return NULL;
	}

	if(compare(head(l),v)==0){
		return l;
	}else{
		return search(tail(l),v);
	}

	return NULL;
}

lista new_elem(tipo_inf inf) {

    elem* p = new elem ;
	strcpy(p->inf,inf);
	p->pun=p->prev=NULL;
	return p;

}

lista tail(lista p){

    return p->pun;

}

lista prev(lista p){

    return p->prev;
    
}

lista insert_elem(lista l, elem* e){
	e->pun = l;
	if(l!=NULL) {
		l->prev = e;
	}
	e->prev = NULL;
	return e;
}

lista delete_elem(lista l, elem* e){

	if(l==e) {
		l = tail(l); // e è la tesata della lista 

	}else {
		(e->prev)->pun = e -> pun;
	}
	delete e;

	return l;
}
