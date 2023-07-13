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
	
		if (l==e)
			l=tail(l);
		else{
		elem* l1=l; 		
		while (tail(l1)!=e)
			l1=tail(l1);
		l1->pun=tail(e);}
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

/* Funzioni */
void stampalista(lista p)
{
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<endl ;
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

lista somma_elem(lista l,int p) {

    int cont = 0;
    lista t = l;
    lista f = l;

    for(cont = 0; cont < p; cont ++ ) {

        t = tail(t);

    }

    int x = head(t);

    while(l != NULL) {

        l->inf = l->inf + x;
        l = tail(l);

    }

    l = f;

    return l;

}

int main()
{
    int n,pos = 0; 
    cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
    //eliminalista(testa);
	//cout << testa <<endl;
    //stampalista(testa);
    cout << "inserisci la posizione dell'elemento da sommare a tutta la lista" << endl;
    cin >> pos;
    testa = somma_elem(testa,pos);
    stampalista(testa);

    return 0;
}
