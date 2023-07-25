#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;

int compare(tipo_inf a, tipo_inf b)
{
	if(strcmp(a.data, b.data) == 0)
		return strcmp(a.orai, b.orai);
	return strcmp(a.data, b.data);
}
void copy(tipo_inf &dest,tipo_inf src)
{
	dest = src;
}
void print(tipo_inf a)
{
	cout << a.data << ": ";
	cout << a.orai << "/";
	cout << a.oraf << " --> ";
	cout << a.descr << endl;
}
