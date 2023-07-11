 #include <iostream>
#include <cstring>

using namespace std ;

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;
 
 /******************************
 *                             *
 * INTESTAZIONE MODULO LISTA   *
 * 							   *
 * ****************************/

lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

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
