#include "exec.h"

exec::exec(lista_parametros recibiendo)
{
    this->parametros=recibiendo.list_parametro;
}

void exec::ejecutar()
{
    imprimir("\t->exec");
    if(!revisarExitanParametros({"path"})){
        return ;
    }

    this->ruta= getParametro("path");

    extern lista_comandos *raiz;
    const char *x =ruta.toUtf8().constData();
    FILE *archivo =fopen(x,"r");
    raiz= new lista_comandos();
    yyrestart(archivo);
    yyparse();
    for(instruccion *x:raiz->comandos){
        x->ejecutar();
    }

}
