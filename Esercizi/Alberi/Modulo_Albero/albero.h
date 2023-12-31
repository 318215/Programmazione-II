/**
 * @file albero.h
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

struct node {
   tipo_inf inf;
   node* parent; //opzionale
	  node* firstChild;
	  node* nextSibling;
};

typedef node* tree;

node* new_node(tipo_inf);
void insert_child(tree, tree);
void insert_sibling(node*, tree);
tipo_inf get_info(node*);
node* get_parent(node*);
node* get_firstChild(node*);
node* get_nextSibling(node*);
void serializza(node*);
int altezza(node *);
bool search(tree, tipo_inf);
bool esiste(node*, node*);
int contaFoglie(node*);