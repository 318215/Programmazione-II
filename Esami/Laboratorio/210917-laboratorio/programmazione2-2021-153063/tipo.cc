#include <iostream>
#include <cstring>
using namespace std;

#include "tipo.h"

int compare (tipo_inf a,tipo_inf b) {
	if ((strcmp(a.data, b.data) == 0) && (strcmp(a.ora_i, b.ora_i) == 0))
			return 0;
	else
		return -1;

}

void copy (tipo_inf &sorg, tipo_inf dest) {
	sorg = dest;
}
void print (tipo_inf a) {
	cout<<a.data<<" "<<a.ora_i<<" "<<a.ora_f<<" "<<a.descr<<endl;
}
