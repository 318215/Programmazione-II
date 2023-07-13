/**
 * @file albero.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "albero-tipo.h"
#include "albero.h"

#include <iostream>

/** Funzione che crea nuovo albero. */

bnode* bst_new_node(tipo_key k,tipo_inf i) {

    bst n = new bnode;

    copia(n->inf,i);
    copiaChiave(n->key,k);
    n->left = NULL;
    n->parent = NULL;
    n->right = NULL;

    return n;
}

/** Funzione che mi ritorna la chiave dato un determinato nodo. */

tipo_key get_key(bnode* n) {

    return n->key;

}

/** Funzione che mi ritorna il valore informativo dato un determinato nodo. */

tipo_inf get_value(bnode* n) {

    return n->inf;

}

/** Funzione che mi ritorna il figlio sinistro dato un determinato nodo. */

bst get_left(bnode* n) {

    return n->left;

}

/** Funzione che mi ritorna il figlio destro dato un determinato nodo. */

bst get_right(bnode* n) {

    return n->right;

}

/** Funzione che mi ritorna il padre dato un detrminato nodo. */

bst get_parent(bnode* n) {

    return n->parent;

}

/** Funzione che inserisce come foglia o sx o dx un nodo passato come parametro alla radice */

void bst_insert(bst& n, bnode* e) { /** < @param Radice, @param Nodo */

    if(n==NULL){ 

        n=e;
        return;
    } 
    if (compareKey(get_key(n),get_key(e))<0) {

        if(get_left(n)!=NULL) {

            bst_insert(n->left,e);

        }else { 

            n->left=e; 
            e->parent=n;

        }

    }else {

        if(get_right(n)!=NULL) {

            bst_insert(n->right,e);

        }else { 

            n->right=e;
            e->parent=n;

        }
    }
}

/** Funzione che rimuove un nodo scelto in input dall'utente.  */

void bst_delete(bst& n, bnode* e) {

    bst p = e;
    if(e->parent == NULL) {
        
        p = n;

    }else {

        p = e->parent;

    }

    if(e->left == NULL && e->right == NULL ) {

        if(get_key(e) > get_key(get_parent(e))) {

            e->parent->right = NULL;

        }else {

            e->parent->left = NULL;
            
        }
        delete e;

    }else if(e->left == NULL && e->right != NULL ) {


        e->right->parent = e->parent;
        if(e->right->key > e->parent->key) {

            e->parent->right = e->right;

        }else {

            e->parent->left = e->right;

        }

        delete e;

    }else if(e->left != NULL && e->right == NULL ) {

        e->left->parent = e->parent;

        if(e->right->key > e->parent->key) {

            e->parent->right = e->left;

        }else {

            e->parent->left = e->left;

        }


        delete e;

    }else {

        p = e->right;

        while(p->left != NULL) {

            p = p->left;

        }

        n=p;

        n->left = e->left;
        e->left->parent = n;
        if(e->right == n) {

            ;

        }else {

            n->right = e->right;
            e->right->parent = n;

        }

        if(e->parent == NULL) {

            n->parent = NULL;

        }

        if(n->parent != NULL ) {

            if(e->parent->key > n->key) {

                e->parent->left = n;

            }else {

                e->parent->right = n;

            }

        }

        delete e;

    }

}

/** Funzione che stampa l'albero scandendo prima il sotto-albero sinistro poi il sotto-albero destro in ordine crescente. */

void bst_dfs(bnode* n) {

    if(get_left(n) != NULL) {

        bst_dfs(get_left(n));

    }

    printChiave(get_key(n));

    if(get_right(n) != NULL) {

        bst_dfs(get_right(n));

    }

}

/** Funzione che permette di ricercare un valore all'interno del nostro albero. */

bnode * bst_search(bst n, tipo_key v) {

    if(n == NULL) {

        return NULL;

    }

    if(compareKey(get_key(n),v) == -1) {

        if(get_left(n) != NULL) {

            n = bst_search(get_left(n),v);
            return n;
        }
         

    }else if(compareKey(get_key(n),v) == 0) {

        if(get_right(n) != NULL) {

            n = bst_search(get_right(n),v);
            return n;

        }

    }else if(compareKey(get_key(n),v) == -2) {

        return n;

    }

    return NULL;


}


bst serach_Ricorsiva(bst t, tipo_inf v) {

    bst p;

    if(t == NULL) {

        return NULL;

    }

    if(compare(t->inf,v) == 0) {

        return t;

    }

    if(t->inf[0] < v[0]) {

        p = serach_Ricorsiva(get_right(t),v);
        return p;

    }

    if(t->inf[0] > v[0] ) {

        p = serach_Ricorsiva(get_left(t),v);
        return p;

    }



}