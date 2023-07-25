/*
 * compito.cc
 *
 *  Created on: 17 set 2021
 *      Author: Simone Nicolini
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include "tipo.h"
#include "liste.h"

using namespace std;



/**
 * funzione agenda che carica in una lista un nuovo evento
 *
 * carica nella lista passata e ne modifica il contentuto aggiungendo
 * il nuovo evento.
 * controllando prima se per quella data e ora ha gia un altro impegno
 *
 * @param l Lista della aggenda passata per parametro
 * @param t un evento da inserire
 */
void agenda (lista &l, tipo_inf t){
	if(search(l, t)!=NULL){
		cout <<"###########"<<endl;
		cout <<"errore: "<<endl;
		print (t);
		cout <<"###########"<<endl;
	}else{
		l=insert_elem(l, new_elem(t));
	}

}

/**
 * funzione stampa un agenda
 *
 * stampa il contenuto di un agenda scorrendo tutta la lista
 *
 * @param l Lista della agenda
 */
void stampa(lista l){
	while (l!=NULL){
		print(head(l));
		l=tail(l);
	}
}

/**
 * funzione agenda che conta gli eventi prima e dopo nella stessa giornata
 *
 * cerca nella lista gli eventi nella stessa giornata e stamoa quanti eventi
 * sono prima e quanti dopo l'evento inserito
 *
 * @param l Lista della agenda
 * @param t un evento da inserire
 */
void quanti(lista l, tipo_inf i){
	int p=0;
	int d=0;

	while(l!=NULL){
		if(strcmp(head(l).data, i.data) == 0){
			if(strcmp(head(l).orai,i.oraf)>0){
				d++;
			}else if(strcmp(head(l).orai,i.oraf)<0){
				p++;
			}

		}
		l=tail(l);

	}

	cout << p << "appuntamenti prima"<<endl;
	cout << d << "appuntamenti dopo"<<endl;

}
/**
 * main del programma per l'acquisizione e stampa dati
 *
 */
int main (){
	lista a=NULL;

	ifstream in("agenda.txt");
	tipo_inf p;

	while (in >> p.data >> p.orai >> p.oraf){
			in.ignore();
			in.getline(p.descr, 51);
			agenda(a, p);
	}

	stampa(a);

	cout << "(2a) inserisci data orai e oraf separati da uno spazio ";
	cin >> p.data >> p.orai >>p.oraf;

	cout << "inserisci breve descrizione";
	cin >> p.descr;

	quanti(a, p);
}
