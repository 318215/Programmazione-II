#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "liste.h"

const char FILENAME1[] = "agenda.txt";

/**
 * @brief Carica gli elementi nella lista
 *
 * @param pi lista
 * @return numero di elementi inseriti
 */
void agenda(lista &l, tipo_inf a) {
	elem *eTemp = new_elem(a);
	elem *s = search(l, a);

	if (s == NULL)
		l = insert_elem(l, eTemp);
	else {
		cout << "Errore nell'inserimento di: ";
		print(a);
	}
}

/**
 * @brief Stampa gli elementi della lista
 *
 * @param l lista da stampare
 */
void stampa(lista l) {
	while (l != NULL) {
		print(head(l));
		l = tail(l);
	}
	cout << endl;
}

/**
 * @brief Stampa gli appuntamenti nello stesso giorno dell'appuntamento in ingresso 'a'
 *
 * @param agenda agenda di appuntamenti
 * @param a appuntamento
 */
/*
 void quanti(lista agenda, tipo_inf a) {
 int prima = 0, dopo = 0;

 cout << g1 << endl;

 while (agenda != NULL) {
 // TODO controllare il giorno non tutta la data
 if (strcmp(a.data, head(agenda).data) == 0) {
 if (strcmp(a.ora_i, head(agenda).ora_i) < 0)
 prima++;
 else if (strcmp(a.ora_i, head(agenda).ora_i) > 0)
 dopo++;
 }
 agenda = tail(agenda);

 }

 cout << prima << " appuntamenti prima e " << dopo << " appuntamenti dopo"
 << endl;
 }
 */
/**
 * @brief Legge una riga fino al carattere '\n'
 *
 * @param is stream
 * @param riga vettore in cui inserire il contenuto letto
 */
const void leggi_riga(istream &is, char *riga) {
	while (is.peek() == '\n')
		is.get();

	is.get(riga, 51);
	is.get();
}

int main() {
	lista l = NULL;

	/*PUNTO 1*/
	fstream in(FILENAME1, ios::in);
	tipo_inf temp;

	cout << "Carico il contenuto..." << endl;

	while (in >> temp.data >> temp.ora_i >> temp.ora_f) {
		leggi_riga(in, temp.descr);
		agenda(l, temp);
	}

	in.close();
	cout << "Contenuto caricato, adesso stampo..." << endl;
	stampa(l);

	/*PUNTO 2.a*/
	/*cout << "Inserire appuntamento di riferimento:" << endl;
	 cout << "anno: ";
	 cin >> temp.data;

	 cout << "ora di inizio: ";
	 cin >> temp.ora_i;

	 cout << "ora di fine: ";
	 cin >> temp.ora_f;

	 cout << "descrizione: ";
	 leggi_riga(cin, temp.descr);

	 quanti(l, temp);*/
	return 0;
}
