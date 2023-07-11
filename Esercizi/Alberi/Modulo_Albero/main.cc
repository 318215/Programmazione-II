/**
 * @file main.cc
 * 
 * 
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


//#define DEBUG
#define DFS
#define BFS

#include <iostream>
using namespace std;

#include "albero-tipo.h"
#include "albero.h"
#include "coda-bfs.h"

/** ::main Funzione main. */

int main(){
	
	tree t=NULL;
	tipo_inf val;
	t=new_node("Luca");
	node* n=new_node("Paolo");
	insert_child(t,n);
#ifdef DEBUG
	cout<<"Root:"<<get_info(t)<<endl;
	cout<<"Root->first child: "<<get_info(get_firstChild(t))<<endl;
#endif
	n=new_node("Marco");
	insert_sibling(t->firstChild,n);
#ifdef DEBUG
	cout<<"Root->second child: "<<get_info(get_nextSibling(get_firstChild(t)))<<endl;
	cout<<"Marco and Paolo's parent:"<<get_info(get_parent(get_firstChild(t)))<<" "<<get_info(get_parent(get_nextSibling(get_firstChild(t))))<<endl;
#endif
	n=new_node("Lucia");
	insert_child(t->firstChild->nextSibling,n);

	node* m=new_node("Anna");
	insert_sibling(n->parent,m);

	n=new_node("Carla");
	insert_child(t->firstChild->nextSibling->firstChild,n);


#ifdef DEBUG
	cout<<"Lucia's parent: "<<get_info(get_parent(n))<<endl;
	cout<<"Root->third child: "<<get_info(get_nextSibling(get_nextSibling(get_firstChild(t))))<<endl;
#endif
	
#ifdef DFS	
	cout << "I componenti dell'albero sono: ";
    serializza(t);
	cout << endl;
	cout << "La profondità dell'albero è: " << altezza(t) << endl;
#endif

#ifdef BFS

	cout << "La dimensione dell'albero è: " << dimensione(t) << endl;
	cout << "La dimensine dell'albero usando la BFS ricorsiva è: " << dimRicorsiva(t) << endl;


#endif

	cout << "Inserisci il valore da ricercare all'interno del nostro albero" << endl;
	cin >> val;
	if(search(t,val) == true) {

		cout << "Valore trovato!" << endl;

	} else {

		cout << "Mi spiace, valore assente." << endl;

	}
	
	cout << "Sappiamo che Luca ha un rapporto padre-figlio con Marco, controlliamo subito se è vero!" << endl;

	if(esiste(get_nextSibling(get_firstChild(t)),get_firstChild(get_firstChild(get_nextSibling(get_firstChild(t))))) == true) {

		cout << "Esiste un rapporto padre-figlio tra loro!!" << endl;

	}else {

		cout << "Non esiste un rapporto padre figlio tra i due nodi." << endl;

	}

	cout << "Il numero di foglie del nostro albero è: " << endl;
	cout << contaFoglie(t);
}
