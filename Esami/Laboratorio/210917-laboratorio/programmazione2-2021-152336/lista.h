typedef bst tipo_lista;

struct elem
{
	tipo_lista inf;
	elem* pun;
};

typedef elem* lista;

lista insert_elem(lista l, elem* i);
elem* new_elem(tipo_lista t);
lista search_delete_elem(lista l, tipo_lista t);
tipo_lista get_lista_inf(elem* i);
lista next(elem* i);

