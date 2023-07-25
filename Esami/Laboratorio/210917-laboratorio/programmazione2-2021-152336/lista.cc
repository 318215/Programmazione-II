/*
  Inplementare le principali funzioni di gestione di una lista semplice, 
  contenente una stringa nel campo informazione.
  In particolare, implementare le funzioni di inserimento in testa, estrazione dalla
  testa, inserimento in fondo, estrazione dal fondo, stampa ed
  eliminazione di una lista semplice.  Scrivere inoltre un main che presenti
  all'utente un menu' per effettuare ciascuna delle precedenti
  operazioni.
*/

#include <iostream>
#include <string.h>
using namespace std ;

#define MAXLEN 20

struct elem
{
       char messaggio[MAXLEN] ;
       elem *pun ;
} ;

typedef elem * lista ;

void eliminalista(lista &testa)
{
     while (testa != 0) {
           elem *q = testa->pun ;

           delete testa ;  //Attenzione: dopo la delete non posso dereferenziare testa!
           testa = q ;  
     }
}

void ins_testa(lista &testa, const char * buf)
{
     // creiamo l'elemento
     elem *p = new elem ;

     strcpy(p->messaggio, buf) ;

     // agganciamo l'elemento
     p->pun = testa ; 
     testa = p ;
}

void stampalista(lista p)
{
     while (p != 0)
     {
          cout<<"Messaggio: "<<p->messaggio<<endl  ;
          p = p->pun ;
     }
     cout<<endl ;
}

int main()
{
	lista testa = 0 ; // NON DIMENTICATE LE INIZIALIZZAZIONI !!!!!

    while (true) {
          int scelta = 0 ;
	  char buf[MAXLEN] ;

          cout<<"\t1 Inserisci in testa\n" ;
          cout<<"\t2 Inserisci in fondo\n" ;
          cout<<"\t3 Estrai dalla testa\n" ;
          cout<<"\t4 Estrai dal fondo\n" ;
          cout<<"\t5 Stampa lista\n" ;
          cout<<"\t6 Elimina lista\n" ;
          cout<<"\t7 Esci\n" ;
          cout<<"Scelta: " ;
          cin>>scelta ;
          switch(scelta) {
	  case 1:
	      cout<<"Messaggio: " ;
	      cin>>buf ;
	      ins_testa(testa, buf) ;
	      break ;
	  case 2:
	      break ;
	  case 3:
	      break ;
	  case 4:
	      break ;
	  case 5:
	      stampalista(testa) ;
	      break ;
	  case 6:
	      eliminalista(testa) ;
	      testa = NULL ; // Ricordatevi di farlo !!!!
	      break ;
	  case 7:
	      return 0;
	  default:
	      cout<<"Scelta non valida\n" ;
		return 1;
          }
    }
    return 0;
}
