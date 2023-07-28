#include <iostream>
#include <cstring>
#include <fstream>
#include "tipo.h"
#include "liste.h"
using namespace std;


void agenda(lista& agenda, tipo_inf a);
void stampa(lista agenda);
void quanti(lista agenda, tipo_inf a);

int main()
{
	ifstream file("agenda.txt");

	lista ag;
	tipo_inf i;
	string t;
	while(file)
	{
		file >> i.data;
		file >> i.orai;
		file >> i.oraf;
		file >> i.descr;
		agenda(ag, i);
	}
	stampa(ag);
	return 0;
}

void agenda(lista& ag, tipo_inf a)
{
	elem* tmp = new_elem(a);

	if(ag != NULL)
	{
		elem* index = ag;

		while(index != NULL)
		{
			if(compare(index->inf, a) == 0)
			{
				cerr << "Elemento gia' presente nella lista." << endl;
				return;
			}
			index = index->pun;
		}
	}
	ag = insert_elem(ag, tmp);
}
void stampa(lista agenda)
{
	elem* tmp = agenda;
	while(tmp != NULL)
	{
		print(tmp->inf);
		tmp = tmp->pun;
	}
}
void quanti(lista agenda, tipo_inf a)
{
	return;
}
