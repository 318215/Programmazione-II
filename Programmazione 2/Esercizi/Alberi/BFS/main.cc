


#define DEBUG

#include <iostream>
using namespace std;

#include "coda-bfs.h"
#include "tipo.h"
#include "tree.h"

void serialize(tree t){
	cout<<"(";
	print(get_info(t));
	tree t1 = get_firstChild(t);
	while(t1!=NULL){
		serialize(t1);
		t1 = get_nextSibling(t1);
	}
	cout<<")";
}

int Dimensione(tree g) {

	int i = 0;

	if(g != NULL) {

		codaBFS Q = newQueue();
		enqueue(Q,g);
		while(!isEmpty(Q)) {
			node* t  = dequeue(Q);
			cout << g->inf;
			if(t->nextSibling != NULL) {

				enqueue(Q,t->nextSibling);
				i++;

			}else if(t->firstChild != NULL) {

				enqueue(Q,t->firstChild);
				i++;

			}

		}

	}

	return i;

}

int main(){
	tree t=NULL;

	t=new_node("Luca");
	node* n=new_node("Paolo");
	insert_child(t,n);
	n=new_node("Marco");
	insert_sibling(t->firstChild,n);
	n=new_node("Lucia");
	insert_child(t->firstChild->nextSibling,n);
	node* m=new_node("Anna");
	insert_sibling(n->parent,m);
#ifdef DEBUG
	serialize(t);
	Dimensione(t);
	cout << Dimensione(t);
#endif

}
