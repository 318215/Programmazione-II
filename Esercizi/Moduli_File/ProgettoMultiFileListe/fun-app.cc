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
/***************************************************
 *                                                  *
 * INTESTAZIONE MODULO FUNZIONI DELL'APPLICAZIONE   *
 * 									                *
 * *************************************************/

elem* search(lista,char*);
char * head(lista);
lista new_elem(lista,elem*);
lista tail(lista);
lista prev(lista);
lista insert_elem(lista,elem*);
lista delete_elem(lista, elem*);

void stampalista(lista p)
{
	cout<<"[";
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}

lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
		  cout<<"URL "<<i<<": " ;
          p = new_elem(testa,p);
          testa=insert_elem(testa,p);
      }
      return testa ;
}

lista cancella(lista l, char* v){
	elem* e;
	while((e=search(l,v))!=NULL){
		cout<<"Cancello un elemento con valore "<<v<<endl;
		l=delete_elem(l,e);}
	cout<<"Fine cancellazione!!"<<endl;
	return l;
}

void naviga(elem* e){
	char scelta;
	cout<< "Trovato!!";
	do{
		cout<< "Cosa vuoi fare (B per backward,F per forward, S per stop)"<<endl;
		cin>>scelta;

		if(scelta == 'B') {


			cout << e->prev->inf;
			e = prev(e);

		}else {

			

			cout << e->pun->inf;
			e = tail(e);

		}
    }		while(scelta!='S');
}
