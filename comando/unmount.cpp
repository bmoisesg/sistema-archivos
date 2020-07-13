#include "unmount.h"

unmount::unmount(lista_parametros entrando)
{
    this->parametros=entrando.list_parametro;
}
void unmount::ejecutar()
{
    imprimir("\t->unmount");
    if(!revisarExitanParametros({"id"}))return;
    this->id=getParametro("id");
    lista_particiones_montadas *unmont= lista_particiones_montadas::getInstance();
    unmont->eliminar(id);
    imprimir("[UNMOUNT] terminado");

}
