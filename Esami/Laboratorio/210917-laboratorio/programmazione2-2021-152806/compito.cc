/*
 * tmp.cc
 *
 *  Created on: 17 set 2021
 *      Author: emaca
 */
#include <iostream>
#include <fstream>
#include <string.h>
#include "liste.h"
#include "tipo.h"

using namespace std;

/** Aggiungeun appuntamento all'agenda
 @param lista& agenda
 @param tipo_inf a
*/
void agenda(lista& agenda, tipo_inf a) {
	elem* app = NULL;
	app = search(agenda, a);
	if(app != NULL) {
		cout << "Errore, non è possibile inserire l'appuntamento: ";
		print(a);
		cout << endl;
	} else {
		agenda = ord_insert_elem(agenda, new_elem(a));
	}
	return;
}

/** Funzione per stampare l'agenda
 Si sfruttano le primitive delle liste per stampare l'agenda
*/
void stampa(lista agenda) {
	while(agenda != NULL) {
		print(head(agenda));
		cout << endl;
		agenda = tail(agenda);
	}
}

void quanti(lista Agenda, tipo_inf a) {
	int prec = 0;
	int seg = 0;
	while(Agenda!=NULL) {
		if(strcmp(head(Agenda).data, a.data) == 0) {
			print(head(Agenda));
			cout << endl;
			if(strcmp(head(Agenda).oraInizio, a.oraInizio) < 0)
				prec++;
			else if(strcmp(head(Agenda).oraInizio, a.oraInizio) > 0)
				seg++;
		}

		// Qui considero come precedenti gli impegni che iniziano prima, per ottenere il risultato desiderato nella consegna bisogna controllare l'orario di fine
		Agenda=tail(Agenda);
	}
	cout << "Precedono: " << prec << endl << "Seguono: " << seg << endl;
}

lista estrai(lista& agenda, char* descr) {
	lista estratti = NULL;
	elem* tmp = agenda;
	while(tmp != NULL) {
		if(strcmp(head(tmp).descr, descr) == 0) {
			estratti = insert_elem(estratti, tmp);
			if(prev(tmp) != NULL) prev(tmp)->pun=tail(tmp);
		}
		tmp=tail(tmp);
	}

	return estratti;
}

int main() {
	ifstream in("agenda.txt");
	lista Agenda = NULL;
	while(in.good()) {
		appuntamento tmp;
		in >> tmp.data;
		in.ignore();
		in >> tmp.oraInizio;
		in.ignore();
		in >> tmp.oraFine;
		in.ignore();
		in.getline(tmp.descr, 51);
		agenda(Agenda, tmp);
	}
	cout << endl;
	stampa(Agenda);
/*
	appuntamento tmp;
	cout << "Inserisci data: ";
	cin >> tmp.data;
	cin.ignore();
	cout << "Inserisci inizio: ";
	cin >> tmp.oraInizio;
	cin.ignore();
	cout << "Inserisci fine: ";
	cin >> tmp.oraFine;
	cin.ignore();
	cout << "Inserisci descr: ";
	cin.getline(tmp.descr, 51);
	cout << endl;
	cout << endl;
	quanti(Agenda, tmp);*/

	char descr[51];
	cout << "Inserisci una descrizione: ";
	cin >> descr;
	lista estratti = estrai(Agenda, descr);
	cout << "Rimossi: " << endl;
	stampa(estratti);
	cout << "Rimasti: " << endl;
	stampa(Agenda);
	return 0;
}
