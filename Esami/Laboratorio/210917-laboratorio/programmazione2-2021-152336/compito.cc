#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#include "tipo.h"
#include "liste.h"

/**	Legge una riga intera ignorando gli spazi
 * 	@param is Stream in input
 * 	@param riga stringa destinazione
 */
void leggi_riga(istream &is, char *riga)
{
	while (is.peek() == '\n')
		is.get();

    is.get(riga, 51);
    is.get();
}


/** Aggiunge l'appuntamento all'agenda solo se nell'agenda non è presente un appuntamento nella stessa data e ora
 *	@param l lista doppia
 *	@param lettura tipo di informazione della lista
 */
void agenda(lista &l, tipo_inf lettura)
{
	if (search(l, lettura) == NULL)
	{
		lista p;
		p = new_elem(lettura);
		l = insert_elem(l, p);
	}
	else
	{
		cout<<"ERRORE: impossibile inserire in agenda l'attivita' "<<lettura.descr<<lettura.data<<" "<<lettura.ora_i<<" "<<lettura.ora_f<<" "<<endl<<endl;
	}
}

/**	Stampa la lista
 * 	@param l lista doppia
 */
void stampa(lista l)
{
	lista punt = l;
	while (punt != NULL)
	{
		print(punt->inf);
		cout<<"-------------"<<endl;
		punt = punt->pun;
	}

}


/** Dato un appuntamento stampa il numero di appuntamenti che precedono nella lista e il numero di appuntamenti che seguono l'appuntamento (dello stesso giorno)
 *	@param agenda lista doppia
 *	@param a tipo di informazione contenuto nella lista
 */
void quanti(lista agenda, tipo_inf a) //esercizio 2.a fatto parzialmente
{
	lista punt = search(agenda, a);

	if (punt == NULL)
		cout<<"Non ho trovato l'appuntamento inserito"<<endl;
	else
	{
		if (strcmp(a.descr, punt->inf.descr) == 0)
		{
			lista punt2 = punt;

			int l, r;
			l == 0;
			r == 0;

			while (punt != NULL)
			{
				//cout<<"ENRTO WHILE"<<endl; ///debug
				l++;
				punt = punt->prev;
			}
			cout<<"Appuntamenti prima: "<<l<<endl;

			while (punt2 != NULL)
			{
				//cout<<"ENRTO WHILE2"<<endl; ///debug
				r++;
				punt2 = punt2->pun;
			}
			cout<<"Appuntamenti dopo: "<<r<<endl;
		}
	}
}




int main()
{

	lista l = NULL;

	ifstream f("agenda.txt");
	if (!f)
	{
	    cerr<<"Errore in apertura del file agenda.txt!";
	    exit(1);
	}

	tipo_inf lettura;

	cout<<"LETTURA DA agenda.txt..."<<endl;
	while (f.eof() == false)
	{

		f>>lettura.data;
		f>>lettura.ora_i;
		f>>lettura.ora_f;
		leggi_riga(f, lettura.descr);

		//print(lettura); //debug
		//cout<<"-------------"; //debug

		agenda(l, lettura);

	}
	f.close();

	stampa(l);

	//esercizio 2.a fatto parzialmente e commentato qua sotto
	/*tipo_inf app;



	cout<<"Stampa del numero degli appuntamenti prima di un preciso appuntamento fornito:"<<endl;
	cout<<"Inserire la data: ";
	cin>>app.data;
	cout<<"Inserire l'ora di inizio: ";
	cin>>app.ora_i;
	cout<<"Inserire l'ora di fine: ";
	cin>>app.ora_f;
	cout<<"Inserire la descrizione: ";
	leggi_riga(cin, app.descr);

	quanti(l, app);*/




	return 0;
}
