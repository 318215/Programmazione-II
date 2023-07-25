/*
 * compito.cc
 *
 *  Created on: 17 set 2021
 *      Author: Gabriel
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


#include "liste.h"

/// procedura agenda
void agenda(lista& agenda, tipo_inf a)
{
	//cerca a in agenda
	//se lo trova stampa errore se no inserisci
	if(search(agenda, a) ==  NULL)
	{
		elem* e = new_elem(a);
		agenda = insert_elem(agenda, e);
	}
	else
	{
		cout << "messaggio di errore per ";
		print(a);
	}

}

//funzione che ritorna la lista utilizzando la procedura agenda
lista init()
{
	lista l = NULL;

	ifstream file("agenda.txt");
	while(file.good())
	{
		tipo_inf prenotazione;
		char desc[51];
		char data[7], inizio[5], fine[5];
		file >> data >> inizio >> fine;

		strcpy(prenotazione.data, data);
		strcpy(prenotazione.ora_i, inizio);
		strcpy(prenotazione.ora_f, fine);

		file.get();
		file.getline(desc, 51, '\n');
		strcpy(prenotazione.descr, desc);

	//cout << prenotazione.data << " " << prenotazione.ora_i << " " << prenotazione.ora_f << " " << prenotazione.descr;
		agenda(l, prenotazione);
		file.get();

	}
	return l;

}

/// procedura che stampa la lista
/** procedura che utilizza la ricorsività*/
void stampa(lista l)
{
	if(l != NULL)
	{
		print(l->inf);
		cout << endl;
		stampa(l->pun);
	}
}
int main()
{
	lista l = init();
	cout << endl;
	stampa(l);

	return 0;
}



