#include <QCoreApplication>
#include "analisis/lista_comandos.h"
#include <analisis/parser.h>
#include <analisis/scanner.h>
#include <iostream>
using namespace std;

int main()
{
        extern lista_comandos *raiz;

    const char *x ="/home/bmoi6/Documents/Qt Proyects/interprete/docs/fase2_entrada.txt";
    FILE *archivo =fopen(x,"r");
    raiz= new lista_comandos();
    yyrestart(archivo);
    yyparse();
    for(instruccion *x:raiz->comandos){
        x->ejecutar();
    }
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    return 0;
/*
    while (true) {
        cout<<">>";
        ofstream archi("tmp_comandos.txt");
        char comando[500];
        std::cin.getline(comando,500,'\n');
        archi<<comando<<endl;
        archi.close();

        const char *x ="tmp_comandos.txt";
        FILE *archivo =fopen(x,"r");
        raiz= new lista_comandos ();
        yyrestart(archivo);
        yyparse();//analisis sintactico
        for(instruccion *x:raiz->comandos){
            x->ejecutar();
        }
        cout<<endl<<endl;

    }*/
    return 0;
}
