/*******************************/
/* HEADER MODULO "liste" */
/*******************************/
struct elem
{
       tipo_inf inf;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

elem* search(lista,tipo_inf);
tipo_inf head(lista);
lista new_elem(tipo_inf);

lista tail(lista);
lista prev(lista);
lista insert_elem(lista,elem*);
lista delete_elem(lista, elem*);
lista ord_insert_elem(lista, elem*);
elem* ord_search(lista, tipo_inf);
