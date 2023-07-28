#include "tipo.h"
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
	copy(p->inf,inf);
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


elem* ord_search(lista l, tipo_inf v){
		while(l!=NULL && compare(head(l),v)<=0)
			if(compare(head(l),v)==0)
				return l;
			else
				l=tail(l);
		return NULL;}


lista ord_insert_elem(lista l, elem* e){
	if(l==NULL || compare(e->inf,head(l))<0)
		return insert_elem(l,e);
	else{
		lista l1=l;
		while (tail(l1)!=NULL && compare(head(tail(l1)),e->inf)<0)
			 l1=tail(l1);
		e->pun = l1->pun;
		if(l1->pun != NULL)
			l1->pun->prev=e;
		l1->pun = e;
		e->prev = l1;
		return l;}
}







