#include "tipo.h"
#include <string.h>
#include <iostream>

using namespace std;

int compare(tipo_inf a1,tipo_inf a2) {
	if(strcmp(a1.data, a2.data) == 0) {
		return strcmp(a1.oraInizio, a2.oraInizio);
	} else {
		return strcmp(a1.data, a2.data);
	}
}
void copy(tipo_inf& a1, tipo_inf a2) {
	strcpy(a1.data, a2.data);
	strcpy(a1.descr, a2.descr);
	strcpy(a1.oraFine, a2.oraFine);
	strcpy(a1.oraInizio, a2.oraInizio);
}

void print(tipo_inf a) {
	cout << a.data << " " << a.oraInizio << " " << a.oraFine << " " << a.descr;
}
