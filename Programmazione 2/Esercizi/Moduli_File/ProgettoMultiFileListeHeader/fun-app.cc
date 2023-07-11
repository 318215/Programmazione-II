#include <iostream>

using namespace std;

#include "liste-tipo.h"
#include "liste.h"
#include "fun-app.h"


void stampalista(lista p)
{
    tipo_inf a;
	cout<<"[";
	while (p != NULL) {
        a = head(p);
		print(a);
        cout << " " ; // stampa valore
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}

lista crealista(int n)
{
      lista testa = NULL ;
      char dato[51];
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
		  cout<<"URL "<<i<<": " ;
          cin >> dato;
          p = new_elem(dato);
          testa=insert_elem(testa,p);
      }
      return testa ;
}

lista cancella(lista l, tipo_inf v){
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

		if(scelta == 'B' && prev(e) != NULL) {

			cout << e->prev->inf;
			e = prev(e);

        }else if(scelta =='B' && prev(e) == NULL){

            cout << "Ultimo elemento!" << endl;

        }else if(scelta == 'F' && tail(e) != NULL) {

			cout << e->pun->inf;
			e = tail(e);

		}else {

            cout << "Ultimo elemento!" << endl;

        }
    }		while(scelta!='S');
}
