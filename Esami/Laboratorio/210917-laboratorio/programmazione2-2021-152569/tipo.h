/*******************************/
/* HEADER MODULO "tipo" */
/*******************************/



struct tipo_inf
{
	char data[7];
	char orai[5];
	char oraf[5];
	char descr[51];
};

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
