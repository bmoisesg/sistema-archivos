#include "mkdisk.h"

mkdisk::mkdisk(lista_parametros entrando)
{
    this->parametros=entrando.list_parametro;
}

void mkdisk::ejecutar(){
    cout<<"\t->mkdisk"<<endl;
    if(!revisarExitanParametros({"path","size"})){
        return;
    }
    this->size= getParametro_int("size");
    if(size==-1){
        imprimirErrorParametro("<size>");
        return;
    }
    this->path= getParametro("path");
    if(revisarParametro("fit")){
        if(tieneQueSer("fit",{"bf","ff","wf"})) {
            this->fit=getParametro("fit");
        }else return;
    }
    if(revisarParametro("unit")){
        if(tieneQueSer("unit",{"k","m"})){
            this->unit=getParametro("unit");
        }else return;
    }

    imprimir("\tpath ->"+path);
    imprimir("\tsize ->"+QString::number(size));
    imprimir("\tfit ->"+fit);
    imprimir("\tunit ->"+unit+"\n");
}
