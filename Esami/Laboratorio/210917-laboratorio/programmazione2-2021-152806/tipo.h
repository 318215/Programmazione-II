/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/
#ifndef tipo_H
#define tipo_H
struct tipo_inf {
	char data[7];
	char oraInizio[5];
	char oraFine[5];
	char descr[51];
};

typedef tipo_inf appuntamento;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);

#endif
