/**
 * @file albero-tipo.h
 * 
 * 
 * @author Manuel Testoni (codebrothers.xyz)
 * @brief 
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

typedef char* tipo_inf;

typedef int tipo_key;

int compare(tipo_inf,tipo_inf);
void copia(tipo_inf&,tipo_inf);
void print(tipo_inf);
int compareKey(tipo_key,tipo_key);
void copiaChiave(tipo_key&,tipo_key);
void printChiave(tipo_key);