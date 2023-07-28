/*
 * tipo.cc
 *
 *  Created on: 17 set 2021
 *      Author: Simone Nicolini
 */

#include <iostream>
#include <string.h>
#include "tipo.h"

using namespace std;

int compare(tipo_inf t1,tipo_inf t2){
	if (strcmp(t1.data,t2.data)==0){
		return strcmp(t1.orai,t2.orai);
	}else return strcmp(t1.data,t2.data);
}
void copy(tipo_inf& t1,tipo_inf t2){
	t1=t2;
}
void print(tipo_inf t){
	cout<<t.data<< " " << t.orai <<" "<<t.oraf << endl << t.descr << endl;
}
