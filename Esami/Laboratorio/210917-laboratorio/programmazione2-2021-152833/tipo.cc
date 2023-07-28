#include <iostream>
#include <cstring>
using namespace std;

#include "tipo.h"

int compare(tipo_inf a, tipo_inf b) {
	if(strcmp(a.data, b.data) == 0) {
		if(strcmp(a.ora_i, b.ora_i) != 0) {
			return strcmp(a.ora_i, b.ora_i);
		}
	}
	return strcmp(a.data, b.data);
}

void copy(tipo_inf &a, tipo_inf b) {
	a = b;
}

void print(tipo_inf a) {
	cout<<a.data<<" "<<a.ora_i<<" "<<a.ora_f<<endl;
	cout<<a.descr<<endl;
}
