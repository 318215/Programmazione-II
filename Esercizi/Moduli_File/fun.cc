#include <iostream>

using namespace std ;

static int a ; // dichiarazione di una variabile globale esterna

void fun() // la funzione ha collegamento esterno
{
    cout<<"La variabile esterna vale: "<<a<<endl ;
}
