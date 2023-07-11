struct elem
{
    char inf[51] ;
    elem* pun ;
    elem* prev;
};

typedef elem* lista ;

elem* search(lista,tipo_inf);
tipo_inf head(lista);
lista new_elem(tipo_inf);

lista tail(lista);
lista prev(lista);
lista insert_elem(lista,elem*);
lista delete_elem(lista, elem*);
