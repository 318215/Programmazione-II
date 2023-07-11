/**
 * @file grafo-tipo.cc
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <cstring>
#include "grafo-tipo.h"

using namespace std;

int compare(tipo_inf s1, tipo_inf s2) {

    return strcmp(s1,s2);

}

void print(tipo_inf s1) {

    cout << s1;

}

void copia(tipo_inf &s1, tipo_inf s2) {

    strcpy(s1,s2);

}