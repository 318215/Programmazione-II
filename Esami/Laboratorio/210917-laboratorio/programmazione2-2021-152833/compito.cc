#include <iostream>
#include <fstream>
using namespace std;

#include "lista.h"

/** Mette all'interno della stringa "riga" una sequenza di caratteri anche contenente
 * 	spazi tra le parole
 */
void leggi_riga(istream &is, char *riga) {
    while (is.peek() == '\n')
            is.get() ;

    is.get(riga, 40) ;
    is.get() ;
}

/** Si ocupa di sistemare l'elemento prima controllando che non sia già presente
 *  nella lista e, se non lo è, allora lo inserisce
 */
void agenda(lista& l, tipo_inf a) {
	elem* app = new_elem(a);

	if(l == NULL) { //caso in cui la lista è vuota
		l = insert_elem(l, app);
	} else {  //lista con almeno 1 elemento
		lista pointer = search(l, a);

		if(pointer != NULL) {
			cout<<"Errore di inserimento dell'appuntamento: "<<endl;
			print(head(pointer));
			cout<<endl<<endl;
		}

		if(pointer == NULL) {
			l = insert_elem(l, app);
		}
	}
}

/** Stampa la lista */
void stampa(lista l) {
	while (l != NULL) {
		print(head(l));
		cout<<endl;
		l = tail(l);
	}
}

/** Crea un puntatore sull'elemento dato in input e successivamente scorre prima
 * 	gli elementi presenti prima di lui nella lista e poi quelli dopo fino a quando
 * 	non arriva a NULL
 */
void quanti(lista l, tipo_inf a) {
	lista p = search(l, a);

	if(p != NULL) {		//caso in cui nella lista non è presente a
		lista app = p;
		int count_prima = 0, count_dopo = 0;

		app = prev(app);		//elementi prima
		while(app != NULL) {
			if(head(p).data[5] == head(app).data[5]) {
				count_prima++;
			}
			app = prev(app);
		}

		app = tail(p);
		while(app != NULL) {	//elementi dopo l'elemento trovato
			if(head(p).data[5] == head(app).data[5]) {
				count_dopo++;
			}
			app = tail(app);
		}

		cout<<count_dopo<<" appuntamenti prima e "<<count_prima<<" appuntamenti dopo"<<endl;
	}
}

int main() {
	lista l = NULL;

	ifstream f("agenda.txt");

	if(!f)
		return 1;

	tipo_inf a;

	while(f>>a.data) {
		f>>a.ora_i;
		f>>a.ora_f;
		leggi_riga(f, a.descr);
		agenda(l, a);
	}

	stampa(l);
	f.close();

	cout<<"Inserire data: ";
	cin>>a.data;
	cout<<"Inserire ora inizio: ";
	cin>>a.ora_i;
	cout<<"Inserire ora fine: ";
	cin>>a.ora_f;
	cout<<"Inserire descrizione: ";
	cin>>a.descr;

	quanti(l, a);
	return 0;
}
