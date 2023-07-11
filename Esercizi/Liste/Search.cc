#include <iostream>

using namespace std ;

struct elem
{
       int inf ;
       elem* pun ;
} ;

typedef elem* lista ;

/* Primitive */

int head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	return e;
}

lista delete_elem(lista l, elem* e){
	
		if (l==e) {

			l=tail(l);

        }else{

		    elem* l1=l; 		

		    while (tail(l1)!=e) {

			    l1=tail(l1);

            }

		    l1->pun=tail(e);

        }

	delete e;
	return l;
	
}

elem* search(lista l, int v) {

    while(l!=NULL){

        if(head(l)==v) {

            return l;

        }else { 

            l=tail(l);
        }
    }

    return NULL;
     
}

elem* search_ricorsiva(lista l, int v) {

    if(l == NULL) {

        return NULL;

    }    

    if(head(l)==v) {

        return l;

    }else { 

        return search_ricorsiva(tail(l),v);
    }
    

    return NULL;
     
}

lista copy(lista l1){ 

    lista l=NULL;
    elem* curr; 
    elem* prev=NULL; //Puntatore ausiliario: punta all’ultimo elemento inserito
    while(l1!=NULL){

        curr = new elem ;
        curr->inf = head(l1);
        curr->pun=NULL;
        if(prev==NULL) { /* sto creando la testa */
        
            l=curr;

        }else {

            prev->pun=curr;
        }

        prev=curr;
        l1=tail(l1);

    }

return l; }

lista delete_elem_ricorsiva(lista l, elem*e) {

    if(l == e) {

        delete_elem_ricorsiva(tail(l),e);

    }else{

		    elem* l1=l; 		

		    while (tail(l1)!=e) {

			    l1=tail(l1);

            }

		    l1->pun=tail(e);

        }

    delete e;
    
    return l;


}

/* Funzioni */
void stampalista(lista p)
{
	if(p == NULL) {

        return;

    }else {
		cout<<head(p)<<" " ; // stampa valore
		return stampalista(tail(p));    // spostamento sul prossimo elemento
	}
	
}


lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"Valore elemento "<<i<<": " ;
          cin>>p->inf ;
          testa=insert_elem(testa,p);
      }
      return testa ;
}


void eliminalista(lista &testa)
{
 
    while(testa != NULL) {

        testa = delete_elem(testa,testa);

    }

}

int conta (lista l, int v) {

    int cont = 0;

    while((l=search(l,v))!= NULL) {

        l = tail(l);
        cont++;

    }

    return cont;

}

lista cancella(lista l, int v) {

    elem* e; 

    while((e=search(l,v))!=NULL) {

        l=delete_elem(l,e);

    }
    
    return l;

}

lista delete_tail_elem(lista l) {

    elem *punt = new elem;
    punt = l;

    while(tail(l) != NULL) {

        l = tail(l);

    }

        delete_elem(punt,l);

    return punt;

}

lista tail_insert_elem(lista l) {

    elem *punt = new elem;
    punt = l;

    while((tail(l)) != NULL) {

        l = tail(l);

    }

        
        elem* e = new elem;
        l->pun = e;
        e->pun = NULL;
        cin >> e->inf;
        
        
    return punt;

}

int lunghezza_lista_ricorsivo(lista l) {

    int i = 1;  //non potevo inizializzarlo a 0 senno ogni chiamata era a 0
                    //inizializzo a 1 così si somma ad ogni chiamata
    if(l == NULL) {

        return i-1;  //ritorno -1 perchè l'ulitma chiamata è per vedere se è null e se è null non c'è l'elemento che viene contato come ultima chiamata

    }else {

        return i + lunghezza_lista_ricorsivo(tail(l)); //avevo bisogno di ritornare una somma tra le varie i durante le chiamate
        
    }


}

int main()
{
    int n,num,occorrenze; 
    cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
    cout << endl;
    cout << "inserisci il numero che ti interessa trovare nella lista" << endl;
    cin >> num;

    elem * p = new elem;

    p = search(testa,num);

    if(p != NULL) {

        cout << "elemento trovato!!" << endl;

    }else {

        cout << "elemento non trovato!!" << endl; 

    }

    cout << lunghezza_lista_ricorsivo(testa);

    /*
    occorrenze = conta(testa,num);
    cout << occorrenze;

    cout << endl;

    testa = cancella(testa,num);
    stampalista(testa);
    

    delete_tail_elem(testa);
    stampalista(testa);

    testa = tail_insert_elem(testa);
    stampalista(testa);
    */


    return 0;
}