/*******************************/
/* HEADER MODULO "carta" 	   */
/*******************************/



struct cartaFedeltà {

    int punti;
    char Nominativo[40];

};

typedef cartaFedeltà tipo_inf;

int compare(tipo_inf,tipo_inf);
void copy(tipo_inf&,tipo_inf);
void print(tipo_inf);
