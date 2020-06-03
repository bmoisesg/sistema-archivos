#include <QCoreApplication>
#include "analisis/lista_comandos.h"
#include <parser.h>
#include <scanner.h>
#include <iostream>
using namespace std;

int main()
{

    extern lista_comandos *raiz;
    const char *x ="/home/bmoi6/Documents/Qt Proyects/interprete/entrada.txt";
    FILE *archivo =fopen(x,"r");
    raiz= new lista_comandos();
    yyrestart(archivo);
    yyparse();
    for(instruccion *x:raiz->comandos){
        x->ejecutar();
    }
    return 0;
}
