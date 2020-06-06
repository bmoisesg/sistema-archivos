#include "rmdisk.h"

rmdisk::rmdisk(lista_parametros in)
{
    this->parametros= in.list_parametro;
}
void rmdisk::ejecutar()
{
    imprimir("\t->rmdisk");
    if(!revisarExitanParametros({"path"})){
        return;
    }
    this->path= getParametro("path");

    while(true){
        imprimir("seguro que queiere eliminar el disco?[S/N]");
        int num=getchar();
        if(num==83|| num==115){//s
            break;
        }else if(num==78|| num==110){//n
            return;
        }
    }
    QString comando="rm \""+path+"\"";
    system(comando.toUtf8().constData());

    imprimir("\tTERMINADO c:");

}
