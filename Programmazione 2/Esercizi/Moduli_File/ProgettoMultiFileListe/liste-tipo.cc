#include <iostream>
#include <cstring>

/* MODULO LISTA TIPO */

using namespace std ;

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

lista tail(lista);
lista prev(lista);
lista insert_elem(lista,elem*);
lista delete_elem(lista, elem*);

 /***********************************
 *                                  *
 * INTESTAZIONE MODULO LISTA TIPO   *
 * 									*
 * *********************************/

char* head(lista p){
	return p->inf;
}

elem* search(lista l, char* v){

	if(l == NULL) {
		return NULL;
	}

	if(strcmp(head(l),v)==0){
		return l;
	}else{
		return search(tail(l),v);
	}
	
	return NULL;
}

lista new_elem(lista l,elem* e) {

	cin>>e->inf;
    e->pun=e->prev=NULL;

	return e;	

}