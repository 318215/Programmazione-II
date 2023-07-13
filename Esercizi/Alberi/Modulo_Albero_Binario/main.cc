/**
 * @file main.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "albero-tipo.h"
#include "albero.h"

using namespace std;

/** ::main Inseriamo in input la dimensione del nostro albero (numero di nodi che ci aspettiamo a fine programma), li stampiamo e dopodichè ricerchiamo un determinato nodo. */

int main () {

    bst N = NULL;
    int dim,key, i = 0, scelta = 0;
    char inf[50];

    do{
        cout << "1: Inserimento Nodo" << endl;
        cout << "2: Stampa Crescente Albero" << endl;
        cout << "3: Cancellazioen Nodo" << endl;
        cout << "4: Ricerca Nodo" << endl;
        cout << "5: Uscita" << endl;
        cin >> scelta;

        switch(scelta) {

            case 1: {

                cout << "Quati nodi vuoi aggiungere?" << endl;
                cin >> dim;

                for(i = 0; i < dim; i ++) {

                    bst h;
                    cout << "VALORE INFORMATIVO ELEMENTO  " << i+1 << ": ";
                    cin >> inf;
                    cout << "CHIAVE ELEMENTO " << i+1 << ": ";
                    cin >> key;
                    h = bst_new_node(key,inf);
                    bst_insert(N,h);        
        
                }

                break;
                
            }

            case 2: {

                cout << "Ecco a te la stampa crescente del tuo BST" << endl;
                bst_dfs(N);

                break;

            }

            case 3: {

                cout << "Che valore vuoi rimuovere dal BST?" << endl;
                cin >> key;
                bst p = bst_search(N,key);

                if(p == NULL) {

                    cout << "Valore non presente all'interno dell'albero mi spiace" << endl;

                }else {

                    cout << "Eliminazione avvenuta con successo!" << endl;
                    bst_delete(N,p);

                }

                break;

            }

            case 4: {

                cout << "Che valore vuoi ricercare nel BST?" << endl;
                cin >> key;
                bst p = bst_search(N,key);

                if(p == NULL) {

                    cout << "Valore non presente all'interno dell'albero mi spiace" << endl;

                }else {

                    cout << "Esiste l'elemento ed è nell'indirizzo: " << p << endl;

                }

                break;

            }

            case 5: {

                cout << "Grazie per aver usato il mio programma" << endl;
                //return 0;

            }

            default: {

                cout << "Valore non previsto" << endl;
                break;

            }


        }
 

    }while(scelta != 5);
    

    cout << "inserisci il carattere da ricercare ricorsivamente " << endl;
    cin >> inf;
    bst p = serach_Ricorsiva(N,inf);

    cout << p->inf;

    return 0;
}