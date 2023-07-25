#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "liste.h"

/** funzione che serve per leggere stringhe conteneti degli spazi
 * @param is
 * @param riga
 */
void leggi_riga(istream &is, char *riga) {
    while (is.peek() == '\n')
            is.get() ;

    is.get(riga, 51) ;
    is.get() ;
}

/** funzione che legge un singolo elemento da file e lo inserisce nella lista
 * @param agenda
 * @param a
 */
void agenda(lista& agenda, tipo_inf a) {
	lista app = agenda;
	if(search(app, a) != NULL) {
			cout<<"errore esiste gia' un appuntamento: ";
			print(a);
			cout<<endl;
		}
	else
		agenda = insert_elem(agenda, new_elem(a));
}

/** funzione che stampa la lista
 * @param agenda
 */
void stampa(lista agenda) {
	while (agenda != NULL) {

		print(agenda->inf);
		agenda = tail(agenda);
	}
}

/** funzione che restituisce il numero di date prima e dopo una iserita in input
 * @param agenda
 * @param a
 */
void quanti(lista agenda, tipo_inf a) {
	lista app1 = agenda;
	lista app2 = agenda;
	app1 = search(app1, a);
	app2 = search(app2, a);
	int pre = 0;
	int post = 0;
	app1 = app1->prev;
	app2 = app2->pun;
	while(app1 != NULL) {
		if(strcmp(app1->inf.data, a.data) == 0) {
			post++;
		}
		app1 = app1->prev;
	}
	while(app2 != NULL) {
			if(strcmp(app2->inf.data, a.data) == 0) {
				pre++;
			}
			app2 = app2->pun;
		}
	cout<<pre<<" appuntamenti prima e "<<post<<" appuntamenti dopo"<<endl;
}


int main() {
	lista age = NULL;
	ifstream f("agenda.txt");
	if (!f)
		cout<<"errore nell'apertura del file"<<endl;

	tipo_inf a;
	while (!f.eof()) {
		f>>a.data;
		f>>a.ora_i;
		f>>a.ora_f;
		leggi_riga(f, a.descr);
		agenda(age, a);
	}
	stampa(age);
	cout<<"-----------------------------------"<<endl;
	tipo_inf b;
	cout<<"inserisci la data: ";
	cin>>b.data;
	cout<<"inserisci l'ora d'inizio: ";
	cin>>b.ora_i;
	cout<<"inserisci l'ora di fine: ";
	cin>>b.ora_f;
	cout<<"inserisci la descrizione: ";
	leggi_riga(cin, b.descr);
	quanti(age, b);
	return 0;
}
