#include "rmdisk.h"

rmdisk::rmdisk(lista_parametros in)
{
    this->parametros= in.list_parametro;
}
void rmdisk::ejecutar()
{
    imprimir("\t->rmdisk");
    if(!revisarExitanParametros({"path"}))return;
    this->path= getParametro("path");
    if(!pregunta_seguridad_para_eliminar()){
         imprimir("[RMDISK] terminado");
         return;
    }

    QString comando="rm \""+path+"\"";
    system(comando.toUtf8().constData());
    imprimir("[RMDISK] <"+path+"> eliminado :s");

}
