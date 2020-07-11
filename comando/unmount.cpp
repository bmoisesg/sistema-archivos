#include "unmount.h"

unmount::unmount(lista_parametros entrando)
{
    this->parametros=entrando.list_parametro;
}
void unmount::ejecutar()
{
    imprimir("estoy en el comando unmont");

}
