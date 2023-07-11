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

elem* search(lista,char*);
char * head(lista);
lista new_elem(lista,elem*);
void stampalista(lista);
lista crealista(int);
lista cancella(lista,char*);
void naviga(elem*);

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