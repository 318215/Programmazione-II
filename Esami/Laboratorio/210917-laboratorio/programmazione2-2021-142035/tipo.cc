/*
 * tipo.cc
 *
 *  Created on: 17 set 2021
 *      Author: Gabriel
 */

#include <iostream>
#include <cstring>
#include "tipo.h"
using namespace std;


int compare(tipo_inf a ,tipo_inf b)
{
	if(strcmp(a.data, b.data) == 0 && strcmp(a.ora_i, b.ora_i)== 0)
	return 0;

	return-1;
}
void copy(tipo_inf& a,tipo_inf b)
{
	strcpy(a.data, b.data);
	strcpy(a.ora_i, b.ora_i);
	strcpy(a.ora_f, b.ora_f);
	strcpy(a.descr, b.descr);
}
void print(tipo_inf a)
{
	cout << a.data << " " << a.ora_i << " " << a.ora_f << " " << a.descr;
}


