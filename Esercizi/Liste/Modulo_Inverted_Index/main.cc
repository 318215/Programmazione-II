/**
 * @file main.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "tipo.h"
#include "liste.h"
#include "parola.h"
#include <cstring>

/** La funzione load permette di creare una nuova lista che legge da file e dopo aver inserito il contenuto del file restituisce il puntatore alla lista. */
parola* load(int& dim) /** < @param IndirizzoDimensione */
{
    ifstream f("inverted.txt");

    if(!f) {

        cerr << "ERRORE DURANTE L'APERTURA DI UN FILE IN LETTURA" << endl;

    }

    f >> dim;

    parola* p = new parola[dim];

    int i = 0, doc;

    

    while(!f.eof()) {

      f >> p[i].p;
      f >> p[i].n_doc;
      p[i].l = NULL;
      for(int j = 0; j < p[i].n_doc; j++) {
        f >> doc;
        lista e = new_elem(doc);
        p[i].l = insert_elem(p[i].l,e);

      }

      i++;

    }

    f.close();
    
    return p;

}

/** La funzione stampa permtte invece di stampare il contenuto della lista per controllare se l'inserimento da file abbia effettivamente avuto successo.*/

void stampa(parola* p,int dim) /** < @param ArrayDinamicoStruct , @param Dimensione */
{

    lista l;

    for(int i = 0; i < dim; i ++) {

      cout << p[i].p << endl;
      l = p[i].l;
      while(l != NULL) {

        cout << head(l) << endl;
        l = tail(l);

      }

    }

}

/* La funzione update ci permette di aggiornare la nostra lista dandole un altro file diverso dal precedente da cui inserire dati. */
void update(parola*& II,char* fileName,int& dim) /** < @param InvertedList, @param NomeFile, @param DimensionePrecedente .*/
{

  ifstream file(fileName);
	int id = 0;
	file >> id;

	while (file.good()) { //file.good() mai vista in classe è una funzione della libreria IOS::STREAM che permette di controllare 
                        //se lo stream è tutto ok, se ci sono errori e cose del genere.
		char word[80];
		file >> word;
		int i = 0;
		bool trovato = false;
		while (i < dim && !trovato) {
			if (strcmp(word, II[i].p) == 0) {
				II[i].l = insert_elem(II[i].l, new_elem(id));
				trovato = true;
			}
			i++;
		}
		if (!trovato) {
			dim++;
			parola* temp = new parola[dim];
			for (int i = 0; i < dim-1; i++) {
				temp[i] = II[i];  //penso equivalga a dire, copia tutti i campi ma non ne sono sicuro.
			}
			II = new parola[dim];
			for (int i = 0; i < dim-1; i++) {
				II[i] = temp[i];  //qua praticamente esegue uno scambio tra i valori dei due array dinamici di struct per poter 
                          //aggiornare la dimensione di quello di partenza dato che da file ha letto una dim > di quella precedente.
			}
			strcpy(II[i].p, word);
			II[i].n_doc = 1;
			II[i].l = NULL;
			II[i].l = insert_elem(II[i].l, new_elem(id));
		}
	}

}

/** Questa funzione controlla dati due char in input quali documenti hanno in comune che li contengono. */

void AND(parola* II,char* W1,char* W2,int dim) /** < @param ArrayDinamicoStruct , @param Parola1, @param Parola2 , @param DimensioneArray */
{

  bool w1 = false;
  bool w2 = false;
  int h = 0,g = 0;

    for(int i = 0; i < dim; i ++) {  //controllo se trovo la prima parola

        if(strcmp(II[i].p,W1) == 0) {

            w1 = true;  
            h = i; //mi segno a che indice dell'array compare
            

        }else if(strcmp(II[i].p,W2) == 0) {  //stessi controlli per la seconda parola.

            w2 = true;
            g = i;
        }
    }
    

    if(w1 == false || w2 == false) {  //se una delle due è falsa comunichiamo all'utente che una o entrambe non sono state trovate.

        cout << "Nessun documento contiene entrambe le parole, perchè una o entrambe potrebbero non esistere" << endl;
        return ;

    }

    int x = 0;

    while (II[h].l != NULL && II[g].l != NULL) {

        if(II[h].l->inf == II[g].l->inf) {

            cout << "Gli elementi sono presenti nel documento: " << head(II[h].l);
            II[h].l = tail(II[h].l);
            II[g].l = tail(II[g].l);
            x++;

        }else {

            II[g].l = tail(II[g].l);

        }

    } 

    if(x == 0) {

      cout << "Gli elementi non hanno documenti in comune... " << endl;

    }


}


/** ::main Nel main raggruppiamo tutte le chiamte a funzione e lo scopo del programma è creare una lista di tipo inverted, che legga da file e si possa aggiornare leggendo da un altro file a scelta dall'utente. */
int main()
{
  /* INIZIO PUNTO 1 */
  int dim = 0;
  parola* p=load(dim);
  stampa(p,dim);
  /* FINE PUNTO 1 */

  /* INIZIO PUNTO 2 */
  char fileName[256];
  cout<<"Inserisci il nome del file:";
  cin>>fileName;
  update(p,fileName,dim);
  cout<<"Post Update:"<<endl;
  stampa(p,dim);
  /* FINE PUNTO 2 */

  /* INIZIO PUNTO 3 */
  cout<<"Inserisci il primo elemento:"<<endl;
  char W1[80];
  cin>>W1;
  cout<<"Inserisci il secondo elemento:"<<endl;
  char W2[80];
  cin>>W2;
  AND(p,W1,W2,dim);
  /* FINE PUNTO 3* */

  return 0;
}
