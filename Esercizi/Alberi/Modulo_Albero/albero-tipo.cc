/**
 * @file albero-tipo.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include <cstring>

using namespace std ;

#include "albero-tipo.h"

/** Funzione che ritorna il comparison tra due dati di tipo tipo_inf. */

int compare(tipo_inf s1,tipo_inf s2){
	return strcmp(s1,s2);
}

/** Funzione che ritorna la copia del primo parametro nel secondo, entrambi di tipo tipo_inf. */

void copia(tipo_inf& dest, tipo_inf source){
	dest=new char[strlen(source)];
	strcpy(dest,source);
}

/** Stampa il valore di dipo tipo_inf. */

void print(tipo_inf inf){
	cout<<inf;
}
