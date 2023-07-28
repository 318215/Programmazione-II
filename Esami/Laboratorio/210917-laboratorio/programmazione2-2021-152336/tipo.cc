#include <iostream>
#include <cstring>

using namespace std;

#include "tipo.h"

int compare(tipo_inf a,tipo_inf b)
{
	if (strcmp(a.data, b.data) == 0 && strcmp(a.ora_i, b.ora_i) == 0)
			return 0;
	else
	{
		if (strcmp(a.data, b.data ) == 0) //data inizio o data sono diversi
			return strcmp(a.ora_i, b.ora_i);
		else
			return strcmp(a.data, b.data);
	}
}


void copy(tipo_inf& dest, tipo_inf source)
{
	strcpy(dest.data, source.data);
	strcpy(dest.ora_i, source.ora_i);
	strcpy(dest.ora_f, source.ora_f);
	strcpy(dest.descr, source.descr);
}


void print(tipo_inf a)
{
	cout<<a.descr<<endl;
	cout<<"Data: "<<a.data<<endl;
	cout<<"Ora inizio: "<<a.ora_i<<endl;
	cout<<"Ora fine: "<<a.ora_f<<endl;
}
