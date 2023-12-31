/*
Il programma consente all'utente di accedere ad una lista di URL. Ogni URL ha al più 50 caratteri.

Il programma presenta un menù all'utente che può
- creare una lista di n URL attraverso la funzione insert_elem()
- cancellare un URL dato dalla lista attraverso la funzione delete_elem()
- stampare la lista attraverso head() e tail()
- cercare un URL nella lista e quindi consentire all'utente di muoversi a piacere avanti (F-forward) e
indietro (B-backward) nella lista a partire dalla posizione del sito cercato fino a quando non digita
S-stop, usando la funzione search()
 
 E' richiesto di completare le primitive che agiscono sui puntatori e la funzione naviga.
 *
 */

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

 /***********************************
 *                                  *
 * INTESTAZIONE MODULO LISTA TIPO   *
 * 									*
 * *********************************/

elem* search(lista,char*);
char * head(lista);
lista new_elem(lista,elem*);

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

char* head(lista p){return p->inf;}

lista new_elem(lista l,elem* e) {

	cin>>e->inf;
    e->pun=e->prev=NULL;

	return e;	

}

/* MODULO LISTA TIPO */

 /******************************
 *                             *
 * INTESTAZIONE MODULO LISTA   *
 * 							   *
 * ****************************/

lista tail(lista);
lista prev(lista);
lista insert_elem(lista,elem*);
lista delete_elem(lista, elem*);

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

/* MODULO LISTA */

 /***************************************************
 *                                                  *
 * INTESTAZIONE MODULO FUNZIONI DELL'APPLICAZIONE   *
 * 									                *
 * *************************************************/

void stampalista(lista);
lista crealista(int);
lista cancella(lista,char*);
void naviga(elem*);


void stampalista(lista p) {
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

/* MODULO FUNZIONI DELL'APPLICAZIONE */

 /***************************** 
 *                            *
 * INTESTAZIONE MODULO MAIN   *
 * 							  *
 * ***************************/

int main()
{
    int n;
    char v[51];
    int scelta;
    lista testa=NULL;
    elem* ris;

    do{
    	cout<< "Cosa vuoi fare?"<<endl;
    	cout<< "1: creare una lista"<<endl;
    	cout<<"2:cancellare valori dalla lista"<<endl;
    	cout<<"3: stampare la lista"<<endl;
    	cout<<"4:cercare valori nella lista"<<endl;
    	cout<<"5:esci"<<endl;
    	cin>>scelta;
    	switch(scelta){

    		case 1: 

				cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    			cin >> n;
    			testa = crealista(n);
    			break;
    		
			case 2: 

				cout<<"Inserire il valore da cancellare:"<<endl;
    			cin>>v;
    			testa=cancella(testa,v);
    			break;
    		
			case 3: 

				stampalista(testa);
				break;

			case 4:

    			cin>>v;
        		ris=search(testa,v);

    			if(ris!=NULL){

    				naviga(ris);

				}else{

    				cout<<"Valore non presente"<<endl;
				}
    			break;
    		
			case 5: 
				cout<<"Ciao, ciao!!"<<endl;
		}

    }while(scelta!=5);

    return 0;
}

/* MODULO MAIN */